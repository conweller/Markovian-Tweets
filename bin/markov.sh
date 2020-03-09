#!/bin/bash
SCRIPTPATH="$( cd "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )"
PIPE=/tmp/markov_PIPE

while getopts ":s:" opt; do
    case $opt in
        s)
            "$SCRIPTPATH"/helper"" "$PWD/${OPTARG}"
            exit
            ;;
        \?)
            echo "Invalid option: -$OPTARG" >&2
            exit 1
            ;;
        :)
            echo "Option -$OPTARG requires an argument." >&2
            exit 1
            ;;
    esac
done

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
