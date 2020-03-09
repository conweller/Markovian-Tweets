#!/bin/bash
pipe=/tmp/markov_pipe

trap "rm -f $pipe" EXIT

if [[ ! -f src/twitter_api.py ]]; then
    echo "error 1"
    exit
fi

if [[ ! -f bin/helper ]]; then
    echo "error 2"
    exit
fi

if [[ ! -p $pipe ]]; then
    mkfifo $pipe
fi

bin/helper $pipe&
helper_pid=$!

python3 src/twitter_api.py $1 > $pipe

(sleep 4; kill -9 "${helper_pid}" >& /dev/null ;exit) &
sleep_pid=$!

wait $helper_pid
kill -PIPE $sleep_pid
wait

exit
