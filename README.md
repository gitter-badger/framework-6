# Corvusoft's C++ Framework

----------

This framework is a collection of functionality that is not specific to an individual Corvusoft solution. It is intended to present a clean and reliable set of interfaces to common business objects and functionality.

## Features

 - Uri datatype
 - Byte datatype
 - Checksum datatype
 - Unique Identifier datatype
 - Map Utilities
 - Date Utilities
 - HTTP Utilities
 - String Utilties
 - Regex Utilities
 - Hexidecimal Encoding

## License

Copyright (c) 2013, 2014, 2015 Corvusoft Limited, United Kingdom. All rights reserved.

Corvusoft's C++ Framework is dual licensed; See LICENSE.md for full details.

## Build

```
#!bash

git clone --recursive http://github.com/corvusoft/framework.git
mkdir framework/build
cd framework/build
cmake [-DBUILD_TESTS=YES] [-DCMAKE_INSTALL_PREFIX=/output-directory] ..
make install
make test
```

You will now find all required components installed in the framework distribution folder.  Please submit all enhancements, proposals, and defects via the [issue](http://github.com/corvusoft/framework/issues) tracker.

## Road Map
 
 - HTTP Session
 - Static Build Option
 - Alternative algorithms for Checksum
 - Better date support
 