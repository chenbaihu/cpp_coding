/**
 * Autogenerated by Thrift Compiler (0.9.2)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef MapService_H
#define MapService_H

#include <thrift/TDispatchProcessor.h>
#include "map_types.h"



class MapServiceIf {
 public:
  virtual ~MapServiceIf() {}
  virtual void compute(ComputeResp& _return, const ComputeReq& req) = 0;
};

class MapServiceIfFactory {
 public:
  typedef MapServiceIf Handler;

  virtual ~MapServiceIfFactory() {}

  virtual MapServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(MapServiceIf* /* handler */) = 0;
};

class MapServiceIfSingletonFactory : virtual public MapServiceIfFactory {
 public:
  MapServiceIfSingletonFactory(const boost::shared_ptr<MapServiceIf>& iface) : iface_(iface) {}
  virtual ~MapServiceIfSingletonFactory() {}

  virtual MapServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(MapServiceIf* /* handler */) {}

 protected:
  boost::shared_ptr<MapServiceIf> iface_;
};

class MapServiceNull : virtual public MapServiceIf {
 public:
  virtual ~MapServiceNull() {}
  void compute(ComputeResp& /* _return */, const ComputeReq& /* req */) {
    return;
  }
};

typedef struct _MapService_compute_args__isset {
  _MapService_compute_args__isset() : req(false) {}
  bool req :1;
} _MapService_compute_args__isset;

class MapService_compute_args {
 public:

  static const char* ascii_fingerprint; // = "4F5322D1DFA268E817C63F14D7EA47A0";
  static const uint8_t binary_fingerprint[16]; // = {0x4F,0x53,0x22,0xD1,0xDF,0xA2,0x68,0xE8,0x17,0xC6,0x3F,0x14,0xD7,0xEA,0x47,0xA0};

  MapService_compute_args(const MapService_compute_args&);
  MapService_compute_args& operator=(const MapService_compute_args&);
  MapService_compute_args() {
  }

  virtual ~MapService_compute_args() throw();
  ComputeReq req;

  _MapService_compute_args__isset __isset;

  void __set_req(const ComputeReq& val);

  bool operator == (const MapService_compute_args & rhs) const
  {
    if (!(req == rhs.req))
      return false;
    return true;
  }
  bool operator != (const MapService_compute_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MapService_compute_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MapService_compute_args& obj);
};


class MapService_compute_pargs {
 public:

  static const char* ascii_fingerprint; // = "4F5322D1DFA268E817C63F14D7EA47A0";
  static const uint8_t binary_fingerprint[16]; // = {0x4F,0x53,0x22,0xD1,0xDF,0xA2,0x68,0xE8,0x17,0xC6,0x3F,0x14,0xD7,0xEA,0x47,0xA0};


  virtual ~MapService_compute_pargs() throw();
  const ComputeReq* req;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MapService_compute_pargs& obj);
};

typedef struct _MapService_compute_result__isset {
  _MapService_compute_result__isset() : success(false), se(false) {}
  bool success :1;
  bool se :1;
} _MapService_compute_result__isset;

class MapService_compute_result {
 public:

  static const char* ascii_fingerprint; // = "DF2DA5C259B4B93EA96C06C95157DBD5";
  static const uint8_t binary_fingerprint[16]; // = {0xDF,0x2D,0xA5,0xC2,0x59,0xB4,0xB9,0x3E,0xA9,0x6C,0x06,0xC9,0x51,0x57,0xDB,0xD5};

  MapService_compute_result(const MapService_compute_result&);
  MapService_compute_result& operator=(const MapService_compute_result&);
  MapService_compute_result() {
  }

  virtual ~MapService_compute_result() throw();
  ComputeResp success;
  ServiceException se;

  _MapService_compute_result__isset __isset;

  void __set_success(const ComputeResp& val);

  void __set_se(const ServiceException& val);

  bool operator == (const MapService_compute_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(se == rhs.se))
      return false;
    return true;
  }
  bool operator != (const MapService_compute_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MapService_compute_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MapService_compute_result& obj);
};

typedef struct _MapService_compute_presult__isset {
  _MapService_compute_presult__isset() : success(false), se(false) {}
  bool success :1;
  bool se :1;
} _MapService_compute_presult__isset;

class MapService_compute_presult {
 public:

  static const char* ascii_fingerprint; // = "DF2DA5C259B4B93EA96C06C95157DBD5";
  static const uint8_t binary_fingerprint[16]; // = {0xDF,0x2D,0xA5,0xC2,0x59,0xB4,0xB9,0x3E,0xA9,0x6C,0x06,0xC9,0x51,0x57,0xDB,0xD5};


  virtual ~MapService_compute_presult() throw();
  ComputeResp* success;
  ServiceException se;

  _MapService_compute_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const MapService_compute_presult& obj);
};

class MapServiceClient : virtual public MapServiceIf {
 public:
  MapServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  MapServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void compute(ComputeResp& _return, const ComputeReq& req);
  void send_compute(const ComputeReq& req);
  void recv_compute(ComputeResp& _return);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class MapServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<MapServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (MapServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_compute(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  MapServiceProcessor(boost::shared_ptr<MapServiceIf> iface) :
    iface_(iface) {
    processMap_["compute"] = &MapServiceProcessor::process_compute;
  }

  virtual ~MapServiceProcessor() {}
};

class MapServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  MapServiceProcessorFactory(const ::boost::shared_ptr< MapServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< MapServiceIfFactory > handlerFactory_;
};

class MapServiceMultiface : virtual public MapServiceIf {
 public:
  MapServiceMultiface(std::vector<boost::shared_ptr<MapServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~MapServiceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<MapServiceIf> > ifaces_;
  MapServiceMultiface() {}
  void add(boost::shared_ptr<MapServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void compute(ComputeResp& _return, const ComputeReq& req) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->compute(_return, req);
    }
    ifaces_[i]->compute(_return, req);
    return;
  }

};



#endif