#!/bin/sh

if [ $# -eq 0 ]; then
  echo "No CL Args provided. new Exit."
  exit 1
fi

execute="cp"
dir="../"
file="template"
ext="cpp"

case "$1" in
"py")
  ext="py"
  ;;
"cpp" | *)
  ext="cpp"
  ;;
esac

execute="$execute $dir$file.$ext ./"
filename="$file.$ext"
session_name="$file"

if [ $# -eq 2 ]; then
  if [ -e $2.$ext ]; then
    echo "$2.$ext already exists in $(pwd)"
    echo
    echo "new Exit to prevent any unintended overwriting of file"
    exit 1
  fi

  execute="$execute && mv $file.$ext $2.$ext"
  filename="$2.$ext"
  session_name="$2"
fi

touch _input.txt
touch _output.txt

eval $execute
if [ $? -ne 0 ]; then
  exit 1
fi

tmux new-session -d -s "$session_name"

tmux send-keys -t "$session_name":1 "nvim ./$filename" C-m

tmux new-window -t "$session_name":2 -n "Fish"
tmux send-keys -t "$session_name":2 "fish" C-m
tmux send-keys -t "$session_name":2 "../buildit.sh $filename"

tmux new-window -t "$session_name":3 -n "Input"
tmux send-keys -t "$session_name":3 "nvim _input.txt" C-m

tmux attach -t "$session_name"
