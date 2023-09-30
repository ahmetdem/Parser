# A simple command-line parser for C++

This script provides a simple command-line parser for C++ applications. It allows you to define options and functions to be executed when those options are parsed.

## Usage

```bash
my_script [options] <args>
```

## Options

```bash
-r, Copy recursively
-w, Overwrite existing files
-d, Copy directories only
-u, Update existing files
-c, Copy symlinks
--help, Display help message
--version, Display version information
```

## Functions
``` bash
copy <from> <to>
say <message>
```

## Adding custom options and functions:

To add a custom option, use the add_custom_option() function. The function takes an Option object as an argument. The Option object must have the following fields:

- ```name```: The name of the option.
- ```description```: A description of the option.
- ```function```: A function to be executed when the option is parsed.

To add a custom function, simply define a function and pass it to the add_custom_option() function.

#### Example: 
``` cpp
#include "parser.h"

void say(const std::string key) {
    std::cout << key << std::endl;
}

int main(int argc, char const *argv[])
{
    CommandLineParser parser;

    CommandLineParser::Option sayOption {"say", "Says anything you put as argument.", 
        [argv]() { say(argv[2]) ; }};

    parser.add_custom_option(sayOption);
    parser.parse(argc, argv);
}

```

```bash
./my_script say Hello!
```

## Building and Running

To build the script, run the following command:

```bash
g++ -o my_script my_script.cpp
```



