#include <config.h>
#include <config/command_mgr.h>
#include <config/cmds_impl.h>
#include <cc/command_interpreter.h>
#include <cc/data.h>
#include <asiolink/io_address.h>
#include <dhcpsrv/cfgmgr.h>
#include <dhcpsrv/subnet_id.h>
#include <dhcpsrv/sanity_checker.h>
#include <dhcp/duid.h>
#include <hooks/hooks.h>
#include <exceptions/exceptions.h>
#include <free_subnet_cmds.h>
#include <free_subnet_cmds_log.h>
#include <util/encode/hex.h>
#include <util/strutil.h>

#include <boost/bind.hpp>
#include <boost/scoped_ptr.hpp>
#include <string>
#include <sstream>

using namespace isc::dhcp;
using namespace isc::data;
using namespace isc::config;
using namespace isc::asiolink;
using namespace isc::hooks;
using namespace std;

namespace isc {
namespace free_subnet_cmds {

/// @brief Wrapper class around subnet command handlers.
class FreeSubnetCmdsImpl : private CmdsImpl {


public:

    int
    subnet4ListHandler(CalloutHandle& handle);

};

int
FreeSubnetCmdsImpl::subnet4ListHandler(CalloutHandle& handle) {
    CfgSubnets4Ptr subnets4 = CfgMgr::instance().getCurrentCfg()->getCfgSubnets4();
    auto subnets = subnets4->getAll();
    ElementPtr subnets_json = Element::createList();
    for (auto s = subnets->cbegin(); s != subnets->cend(); ++s) {
        // Information for the individual subnets is held in the map.
        ElementPtr element = Element::createMap();
        auto subnet = *(*s);
        element->set("id", Element::create(static_cast<long int>(subnet.getID())));
        element->set("subnet", Element::create(subnet.toText()));
        subnets_json->add(element);
    }
    ElementPtr args = Element::createMap();
    args->set("subnet4", subnets_json);
    ConstElementPtr response =
            createAnswer(subnets_json->size() > 0 ?
                         CONTROL_RESULT_SUCCESS :
                         CONTROL_RESULT_EMPTY,
                         "subnets found", args);
    setResponse(handle, response);
    return (0);
}

/// FreeSubnetCmds methods
int
FreeSubnetCmds::subnet4ListHandler(CalloutHandle& handle) {
    return(impl_->subnet4ListHandler(handle));
}

FreeSubnetCmds::FreeSubnetCmds()
    :impl_(new FreeSubnetCmdsImpl()) {
}

};
};

