#include "../include/parser.h"

void say(const std::string key) {
    std::cout << key << std::endl;
}

void removeFiles (const std::string path) {
    fs::remove_all(path);
}

int main(int argc, char const *argv[])
{
    CommandLineParser parser;

    CommandLineParser::Option sayOption {"say", "Says anything you put as argument.", 
        [argv]() { say(argv[2]) ; }};
    CommandLineParser::Option removeOption {"remove", "Removes all contents from a file or folder.", 
        [argv]() { removeFiles( argv[2] ); }};

    parser.add_custom_option(sayOption);
    parser.add_custom_option(removeOption);
    
    
    CommandLineParser::ShortFlag noneFlag {"-n", fs::copy_options::none};
    parser.add_custom_flag(noneFlag);

    
    parser.parse(argc, argv);

    return 0;
}
