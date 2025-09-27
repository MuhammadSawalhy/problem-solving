import sys

sys.setrecursionlimit(1 << 25)


class TrieNode:
    __slots__ = ["children", "count", "xor_sum", "lazy_xor"]

    def __init__(self):
        self.children: list[TrieNode | None] = [None, None]  # 0, 1
        self.count = 0
        self.xor_sum = 0
        self.lazy_xor = 0


class XORTrie:
    def __init__(self, bits=20):
        self.root = TrieNode()
        self.bits = bits

    def apply_xor(self, node, xor_val, level):
        if not node or xor_val == 0:
            return
        # Apply the XOR to the current node's sum
        if (node.count % 2) == 1:
            node.xor_sum ^= xor_val
        # Propagate the XOR to children via lazy if not leaf
        if level < self.bits - 1:
            # Determine which bits affect this level
            bit = (xor_val >> (self.bits - 1 - level)) & 1
            if bit:
                # Swap children
                node.children[0], node.children[1] = node.children[1], node.children[0]
                # Toggle the lazy for lower bits
                lower_mask = (1 << (self.bits - 1 - level)) - 1
                lower_xor = xor_val & lower_mask
                node.lazy_xor ^= lower_xor

    def push(self, node, level):
        if node.lazy_xor == 0 or level >= self.bits - 1:
            return
        # Propagate the lazy XOR to children
        for i in 0, 1:
            if node.children[i]:
                self.apply_xor(node.children[i], node.lazy_xor, level + 1)
        node.lazy_xor = 0

    def pull(self, node):
        node.xor_sum = 0
        node.count = 0
        for i in 0, 1:
            if node.children[i]:
                node.xor_sum ^= node.children[i].xor_sum
                node.count += node.children[i].count

    def insert(self, x):
        node = self.root
        path = []
        for level in range(self.bits):
            path.append(node)
            bit = (x >> (self.bits - 1 - level)) & 1
            if not node.children[bit]:
                node.children[bit] = TrieNode()
            self.push(node, level)
            node = node.children[bit]
        # Update leaf
        node.count += 1
        node.xor_sum ^= x
        # Propagate back up
        for node in reversed(path):
            self.pull(node)

    def extract_range(self, l, r):
        # Split the trie into values <= r and > r
        right_part = self._split(self.root, r + 1, 0)
        # Split the left part into < l and >= l
        left_part = self._split(right_part, l, 0)
        # The extracted part is left_part (values >= l and <= r)
        extracted = XORTrie(self.bits)
        extracted.root = left_part
        # Rebuild the original trie (values < l or > r)
        self.root = self._merge(right_part, self.root, 0)
        return extracted

    def _split(self, node, x, level):
        if not node or level >= self.bits:
            return None
        self.push(node, level)
        bit = (x >> (self.bits - 1 - level)) & 1
        left_child = node.children[0]
        right_child = node.children[1]
        if bit == 0:
            # Split left subtree
            left_split = self._split(left_child, x, level + 1)
            new_node = TrieNode()
            new_node.children[0] = left_split
            new_node.children[1] = right_child
            # Update counts
            new_node.count = (left_split.count if left_split else 0) + (
                right_child.count if right_child else 0
            )
            new_node.xor_sum = (left_split.xor_sum if left_split else 0) ^ (
                right_child.xor_sum if right_child else 0
            )
            return new_node
        else:
            # Split right subtree
            right_split = self._split(right_child, x, level + 1)
            new_node = TrieNode()
            new_node.children[0] = left_child
            new_node.children[1] = right_split
            # Update counts
            new_node.count = (left_child.count if left_child else 0) + (
                right_split.count if right_split else 0
            )
            new_node.xor_sum = (left_child.xor_sum if left_child else 0) ^ (
                right_split.xor_sum if right_split else 0
            )
            return new_node

    def _merge(self, a, b, level):
        if not a:
            return b
        if not b:
            return a
        if level >= self.bits:
            merged = TrieNode()
            merged.count = a.count + b.count
            merged.xor_sum = a.xor_sum ^ b.xor_sum
            return merged
        self.push(a, level)
        self.push(b, level)
        merged = TrieNode()
        merged.children[0] = self._merge(a.children[0], b.children[0], level + 1)
        merged.children[1] = self._merge(a.children[1], b.children[1], level + 1)
        merged.count = (merged.children[0].count if merged.children[0] else 0) + (
            merged.children[1].count if merged.children[1] else 0
        )
        merged.xor_sum = (merged.children[0].xor_sum if merged.children[0] else 0) ^ (
            merged.children[1].xor_sum if merged.children[1] else 0
        )
        return merged

    def apply_xor_update(self, xor_val):
        self._apply_xor_to_node(self.root, xor_val, 0)

    def _apply_xor_to_node(self, node, xor_val, level):
        if not node or level >= self.bits:
            return
        self.apply_xor(node, xor_val, level)
        # Propagate the remaining XOR to children
        lower_level = level + 1
        lower_mask = (1 << (self.bits - lower_level)) - 1
        lower_xor = xor_val & lower_mask
        for i in 0, 1:
            if node.children[i]:
                self._apply_xor_to_node(node.children[i], lower_xor, lower_level)
        # Update the node's sum and count after applying
        self.pull(node)

    def query_xor_sum(self):
        return self.root.xor_sum if self.root else 0


def main():
    import sys

    input = sys.stdin.read().split()
    ptr = 0
    N = int(input[ptr])
    ptr += 1
    Q = int(input[ptr])
    ptr += 1

    trie = XORTrie(bits=20)  # Adjust bits based on max value (5e5 needs ~19 bits)

    for _ in range(N):
        x = int(input[ptr])
        ptr += 1
        trie.insert(x)

    output = []
    for _ in range(Q):
        cmd = input[ptr]
        ptr += 1
        if cmd == "1":
            x = int(input[ptr])
            ptr += 1
            trie.insert(x)
        elif cmd == "2":
            l = int(input[ptr])
            ptr += 1
            r = int(input[ptr])
            ptr += 1
            x = int(input[ptr])
            ptr += 1
            # Extract the range [l, r]
            extracted = trie.extract_range(l, r)
            # Apply the XOR update to the extracted tree
            extracted.apply_xor_update(x)
            # Merge back into the original trie
            trie.root = trie._merge(trie.root, extracted.root, 0)
        elif cmd == "3":
            l = int(input[ptr])
            ptr += 1
            r = int(input[ptr])
            ptr += 1
            # Extract the range [l, r]
            extracted = trie.extract_range(l, r)
            # Get the XOR sum
            xor_sum = extracted.query_xor_sum()
            # Merge back
            trie.root = trie._merge(trie.root, extracted.root, 0)
            output.append(str(xor_sum))

    print("\n".join(output))


if __name__ == "__main__":
    main()
