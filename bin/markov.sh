#!/bin/bash
SCRIPTPATH="$( cd "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )"
PIPE=/tmp/markov_PIPE

trap "rm -f $PIPE" EXIT

if [[ ! -f ""$SCRIPTPATH"/twitter_api.py" ]]; then
    echo "error 1"
    exit
fi

if [[ ! -f ""$SCRIPTPATH"/helper" ]]; then
    echo "error 2"
    exit
fi

if [[ ! -p $PIPE ]]; then
    mkfifo $PIPE
fi

"$SCRIPTPATH"/helper"" $PIPE&
helper_pid=$!

python3 ""$SCRIPTPATH"/twitter_api.py" $1 > $PIPE

(sleep 4; kill -9 "${helper_pid}" >& /dev/null ;exit) &
sleep_pid=$!

wait $helper_pid
kill -PIPE $sleep_pid
wait

exit
