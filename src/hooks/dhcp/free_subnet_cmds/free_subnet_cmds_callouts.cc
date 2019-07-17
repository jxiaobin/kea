#include <config.h>

#include <free_subnet_cmds.h>
#include <free_subnet_cmds_log.h>
#include <cc/command_interpreter.h>
#include <hooks/hooks.h>

using namespace isc::config;
using namespace isc::data;
using namespace isc::hooks;
using namespace isc::free_subnet_cmds;

extern "C" {

/// @return 0 if this callout has been invoked successfully,
/// 1 otherwise.
int free_subnet4_list(CalloutHandle& handle) {
    FreeSubnetCmds subnet_cmds;
    return(subnet_cmds.subnet4ListHandler(handle));
}

/// @brief This function is called when the library is loaded.
///
/// @param handle library handle
/// @return 0 when initialization is successful, 1 otherwise
int load(LibraryHandle& handle) {
    handle.registerCommandCallout("free-subnet4-list", free_subnet4_list);
    LOG_INFO(free_subnet_cmds_logger, FREE_SUBNET_CMDS_INIT_OK);
    return (0);
}

/// @brief This function is called when the library is unloaded.
///
/// @return 0 if deregistration was successful, 1 otherwise
int unload() {
    LOG_INFO(free_subnet_cmds_logger, FREE_SUBNET_CMDS_DEINIT_OK);
    return (0);
}

} // end extern "C"
