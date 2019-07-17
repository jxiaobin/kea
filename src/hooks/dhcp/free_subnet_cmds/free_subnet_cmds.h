#ifndef FREE_SUBNET_CMDS_H
#define FREE_SUBNET_CMDS_H

#include <cc/data.h>
#include <hooks/hooks.h>

#include <boost/shared_ptr.hpp>

namespace isc {
namespace free_subnet_cmds {

/// @brief Forward declaration of implementation class.
class FreeSubnetCmdsImpl;

/// @brief Implements the logic for subnet operations
///
/// Used by subnet callouts
class FreeSubnetCmds {
public:
    /// @brief Constructor.
    ///
    /// Creates an instance of the @c LeaseCmdsImpl.
    FreeSubnetCmds();

    int
    subnet4ListHandler(hooks::CalloutHandle& handle);

private:
    /// Pointer to the implementation
    boost::shared_ptr<FreeSubnetCmdsImpl> impl_;
};

};
};

#endif
