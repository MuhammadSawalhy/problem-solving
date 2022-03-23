#!/bin/bash

problem_dir="$1"
problem_file=
comment_string=
problem_name="$(sed -E "s/^(\w+.)/\1 /;s/-|_/ /g" <<< "$problem_dir")"
extra_comment=()

if [ -z "$problem_dir" ]; then
  echo "You should specify the problem dir" >&2
  exit 1
fi

if [ ! -d "$problem_dir" ]; then
  echo "Directory \"$problem_dir\" not found" >&2
  exit 1
fi

function prepare() {
  [ ! -f "$problem_dir/main.$1" ] &&
    return 1
  problem_file="$problem_dir/main.$1"
  comment_string="$2"
}

prepare "cpp"  "// " ||
prepare "java" "// " ||
prepare "py"   "# "  ||
{
  echo "No solution code in \"$problem_dir\" found" >&2
  exit 1
}

while read -r line; do
  echo "$line" | grep "$comment_string" &>/dev/null || break
  extra_comment+=("${line/#$comment_string/}")
done < "$problem_file"

git add "$problem_dir"
git cm "add $problem_name problem" -m "$(printf "%s\n" "${extra_comment[@]}")"
