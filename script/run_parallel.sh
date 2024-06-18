#!/bin/bash

# --- Configuration ---

# Define default values for options
DEFAULT_NPARTS=10
DEFAULT_NCHUNKS=100
DEFAULT_EXTRA_OPTS=""

# Create necessary directories
logDir="./log"
mkdir -p "${logDir}"
chmod 755 "${logDir}"

# Function to display help
display_help() {
  echo "Usage: $0 executable [options]"
  echo ""
  echo "Options:"
  echo "  -nparts <number>   Number of parts each chunk is divided into (default: $DEFAULT_NPARTS)"
  echo "                     This specifies how many parts each chunk will be split into."
  echo "  -nchunks <number>  Number of chunks to run in parallel (default: $DEFAULT_NCHUNKS)"
  echo "                     This specifies the number of chunks that will be processed concurrently."
  echo "  -opt <string>      Extra options to pass to the executable (default: \"$DEFAULT_EXTRA_OPTS\")"
  echo "  -h                 Display this help message"
  echo ""
  echo "Example:"
  echo "  $0 events.o -nparts 10 -nchunks 100 -opt \"--some-extra-option value\""
}

# Function to run the process in parallel
run_parallel() {
  local executable=$1
  shift

  local nparts=$DEFAULT_NPARTS
  local nchunks=$DEFAULT_NCHUNKS
  local extra_opts=$DEFAULT_EXTRA_OPTS

  # Parse options
  while [[ $# -gt 0 ]]; do
    case $1 in
      -nparts)
        nparts=$2
        shift 2
        ;;
      -nchunks)
        nchunks=$2
        shift 2
        ;;
      -opt)
        extra_opts=$2
        shift 2
        ;;
      -h)
        display_help
        exit 0
        ;;
      *)
        echo "Unknown option: $1"
        display_help
        exit 1
        ;;
    esac
  done

  run_process() {
    local i=$1
    nohup ./"$executable" -i "$i" -n "$nparts" -k "$nchunks" $extra_opts > "${logDir}/output_${i}.log" 2>&1 &
  }

  export -f run_process

  echo "Running $executable with -n $nparts, -k $nchunks, and extra options: $extra_opts in parallel."
  seq 0 $(($nchunks-1)) | parallel -j0 run_process {}
  wait
}

# Check if -h is an argument
for arg in "$@"; do
  if [[ "$arg" == "-h" ]]; then
    display_help
    exit 0
  fi
done

# Check if at least one argument is passed
if [[ $# -lt 1 ]]; then
  echo "Error: No executable specified."
  display_help
  exit 1
fi

# Example usage