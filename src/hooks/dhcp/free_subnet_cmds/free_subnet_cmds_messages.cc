// File created from ../../../../src/hooks/dhcp/free_subnet_cmds/free_subnet_cmds_messages.mes on Sun Jul 14 2019 14:10

#include <cstddef>
#include <log/message_types.h>
#include <log/message_initializer.h>

extern const isc::log::MessageID FREE_SUBNET_CMDS_ADD4 = "FREE_SUBNET_CMDS_ADD4";
extern const isc::log::MessageID FREE_SUBNET_CMDS_DEINIT_OK = "FREE_SUBNET_CMDS_DEINIT_OK";
extern const isc::log::MessageID FREE_SUBNET_CMDS_INIT_OK = "FREE_SUBNET_CMDS_INIT_OK";

namespace {

const char* values[] = {
    "FREE_SUBNET_CMDS_ADD4", "free-subnet4-add command successful (parameters: %1)",
    "FREE_SUBNET_CMDS_DEINIT_OK", "unloading Free Subnet Commands hooks library successful",
    "FREE_SUBNET_CMDS_INIT_OK", "loading Free Subnet Commands hooks library successful",
    NULL
};

const isc::log::MessageInitializer initializer(values);

} // Anonymous namespace

