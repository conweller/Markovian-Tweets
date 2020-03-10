# Markovian Tweets

A simple tweet generator. Takes a Twitter username or text file and generates a
tweet in the style of that source material user using Markov Chains.

## Setup
Build and run with:
```sh
make
```

For you to run this with a twitter account as the source text, your twitter app
key and secret key need to exist as environment variables. Store them in the
following variables

```sh
export MARKOV_KEY=<your-key-here>
export MARKOV_SECRET=<your-key-here>
```

Generate a tweet using an account as the source text like this:
```sh
bin/markov <twitter-username-here>
```

For you to run this with a text file as the source text, use the `-s` flag
followed by the name of the file you're using:
```sh
bin/markov -s <input text file name>
```
