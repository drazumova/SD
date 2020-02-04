#ifndef HW01_CLI_COMMAND_H
#define HW01_CLI_COMMAND_H

#include <commands/CommandName.h>
#include <commands/CommandArguments.h>

class Command {
public:
    Command() = default;

    Command(
            const CommandName &commandName,
            const CommandArguments &commandArguments
    );

    const CommandName &getCommandName() const;

    const CommandArguments &getCommandArguments() const;

    std::string asString() const;

private:
    CommandName commandName;
    CommandArguments commandArguments;
};


#endif //HW01_CLI_COMMAND_H
