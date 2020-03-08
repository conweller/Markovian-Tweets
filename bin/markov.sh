#!/bin/bash
pipe=/tmp/markov_pipe

trap "rm -f $pipe" EXIT

if [[ ! -f input.txt ]]; then
    exit
fi

if [[ ! -f bin/helper ]]; then
    exit
fi

if [[ ! -p $pipe ]]; then
    mkfifo $pipe
fi

bin/helper $pipe&
helper_pid=$!
(sleep 4; kill -9 "${helper_pid}" >& /dev/null ;exit) &
sleep_pid=$!

# Replace next line with python output
cat input.txt > $pipe

wait $helper_pid
kill -PIPE $sleep_pid
wait

exit
