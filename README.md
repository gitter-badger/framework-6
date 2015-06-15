# Corvusoft's C++ Framework

----------

C++ framework is a collection of functionality that is not specific to an individual Corvusoft solution. It's intended to present a clean and reliable set of interfaces to common business objects and functionality.

## Features

 - Map Utilities
 - Uri Utilities
 - HTTP Utilities
 - String Utilties
 - Unique Identifier
 - Checksum Generators

## License

Copyright (c) 2013, 2014, 2015 Corvusoft Limited, United Kingdom. All rights reserved.

Corvusoft's C++ Framework is dual licensed; See LICENSE.md for full details.

## Build

```
#!bash

git clone --recursive http://github.com/corvusoft/framework.git
mkdir framework/build
cd framework/build
cmake [-DBUILD_TESTS=YES] [-DBUILD_EXAMPLES=YES] [-DCMAKE_INSTALL_PREFIX=/output-directory] ..
make install
make test
```

You will now find all required components installed in the restbed distribution folder.  Please submit all enhancements, proposals, and defects via the issue tracker.

## Road Map
 
 - HTTP Session
 - Static Build Option
