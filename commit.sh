#!/bin/bash

if [ -z "$1" ]; then
  echo "You should specify the problem dir" >&2
  exit 1
fi

if [ ! -d "$1" ]; then
  echo "Directory \"$1\" not found" >&2
  exit 1
fi

problem_dir="$1"
problem_file="$problem_dir/main.cpp"
problem_name="$(sed -E "s/^(\w+.)/\1 /;s/-|_/ /g" <<< "$problem_dir")"
comment_string="// "
extra_comment=()

while read -r line; do
  echo "$line" | grep "$comment_string" &>/dev/null || break
  extra_comment+=("${line/#$comment_string/}")
done < "$problem_file"

git add "$problem_dir"
git cm "add $problem_name problem" -m "$(printf "%s\n" "${extra_comment[@]}")"
