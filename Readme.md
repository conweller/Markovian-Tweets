# Markovian Tweets

A simple tweet generator. Takes a Twitter username and generates a tweet in the
style of that Twitter user using Markov Chains.

## Setup
Build and run with:
```sh
make
```

For you to run this, your twitter app key and secret key need to exist as
environment variables. Store them in the following variables

```sh
export MARKOV_KEY=<your-key-here>
export MARKOV_SECRET=<your-key-here>
```

Run with:
```sh
bin/markov.sh <twitter-username-here>
```
or
```sh
bin/markov.sh -s <input text file name>
```
