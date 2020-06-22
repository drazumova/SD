#include <Shell.h>

#include <processors/LoopProcessor.h>
#include <iostream>

int Shell::run() {
    std::string input;
    while (true) {
        std::getline(std::cin, input);
        Response response = processor->process(
                input,
                *environment,
                *fileTreeState
        );

        StringChannel output = response.getStringChannel();
        std::cout << output.read();

        if (response.getStatus().getExitStatus() == ExitStatus::EXIT) {
            return response.getStatus().getExitCode();
        }
    }
}

Shell::Shell() :
        processor(new LoopProcessor()),
        environment(new Environment()),
        fileTreeState(new FileTreeState()){
}

Shell::~Shell() {
    delete fileTreeState;
    delete processor;
    delete environment;
}
