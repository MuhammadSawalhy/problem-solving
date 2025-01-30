import heapq

def is_graphical(degrees):
    total = sum(degrees)
    if total % 2 != 0:
        return False  # Sum of degrees must be even

    # Use a max-heap to efficiently manage the degrees
    heap = [(-d, i) for i, d in enumerate(degrees) if d > 0]
    heapq.heapify(heap)

    while heap:
        neg_d, u = heapq.heappop(heap)
        d = -neg_d

        # Collect the next d players with the highest degrees
        paired = []
        for _ in range(d):
            if not heap:
                return False  # Not enough players to pair
            neg_d2, v = heapq.heappop(heap)
            paired.append((neg_d2 + 1, v))  # Decrease their degree by 1

        # Push the updated degrees back to the heap
        for new_neg_d, v in paired:
            if new_neg_d < 0:
                heapq.heappush(heap, (new_neg_d, v))

    return True

def construct_graph(degrees, n):
    edges = []
    # Use a max-heap to efficiently get the player with the highest remaining degree
    heap = [(-degrees[i], i + 1) for i in range(n)]
    heapq.heapify(heap)
    while heap:
        neg_d, u = heapq.heappop(heap)
        d = -neg_d
        if d == 0:
            continue
        # Collect the next d players with the highest degrees
        paired = []
        for _ in range(d):
            if not heap:
                return []  # Not enough players to pair
            neg_d2, v = heapq.heappop(heap)
            paired.append((neg_d2, v))
            edges.append((u, v))
        # Decrease the degrees of the paired players and push them back to the heap
        for neg_d2, v in paired:
            if neg_d2 + 1 < 0:
                heapq.heappush(heap, (neg_d2 + 1, v))
    return edges

def main():
    n = int(input())
    x = list(map(int, input().split()))
    if not is_graphical(x):
        print("IMPOSSIBLE")
        return
    edges = construct_graph(x, n)
    print(len(edges))
    for u, v in edges:
        print(u, v)

if __name__ == "__main__":
    main()

