## About

A simple C++ extension for node

### Requirements for building

For building this from scratch, install node-gyp and node headers.

    npm install -g node-gyp
    node-gyp install

To Build: run `cd sample-node-plugin && node-gyp configure build`

The plugin will be `build\Release\octoberlibrary.node`

## Usage and API

#### hf(string)

**hf()** Hash a string (alias: "**hash**")

Example:

    hf = require('./octoberlibrary.node').hf;

    hf('hash this stuff for me');
    // 1404204226
    
    
## Tests

Run tests by `./test`... (requires `chmod u+x ./test`)

