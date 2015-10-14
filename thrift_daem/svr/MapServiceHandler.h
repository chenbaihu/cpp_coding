// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.
#ifndef _MAP_SERVICE_H_
#define _MAP_SERVICE_H_

#include "MapService.h"

#include <string>
#include <map>
using std::string;
using std::map;

#ifndef DAsyncMapCli

class MapServiceHandler : virtual public MapServiceIf 
{
 public:
     MapServiceHandler();
     
     void compute(ComputeResp& _return, const ComputeReq& req);
};

#endif //#ifndef DAsyncMapCli

#endif //_MAP_SERVICE_H_
