#ifndef  _GLUA_CONTRACTOPERATIONS_H_
#define  _GLUA_CONTRACTOPERATIONS_H_

#include <base/misc.hpp>
#include <glua/glua_contractentry.hpp>
#include <glua/lua_lib.h>

#include <fc/reflect/reflect.hpp>

#include <stdint.h>
#include <string>

struct ContractOperation {
    virtual  void evaluate(TaskAndCallback& _inst_taskandcallback, TaskImplResult* result) const = 0;
};

struct RegisterContractOperation : ContractOperation {
    static const OperationTypeEnum type;
    RegisterContractOperation() {}
    virtual void evaluate(TaskAndCallback& _inst_taskandcallback, TaskImplResult* result) const;
};

struct UpgradeContractOperation: ContractOperation {
    static const OperationTypeEnum type;
    
    UpgradeContractOperation() {}
    virtual void evaluate(TaskAndCallback& _inst_taskandcallback, TaskImplResult* result) const;
};

struct DestroyContractOperation: ContractOperation {
    static const OperationTypeEnum type;
    DestroyContractOperation() {}
    virtual void evaluate(TaskAndCallback& _inst_taskandcallback, TaskImplResult* result) const;
};

struct CallContractOperation : ContractOperation  {
    static const OperationTypeEnum type;
    CallContractOperation() {}
    virtual void evaluate(TaskAndCallback& _inst_taskandcallback, TaskImplResult* result) const;
};

struct TransferContractOperation  : ContractOperation {
    static const OperationTypeEnum type;
    TransferContractOperation() {}
    virtual void evaluate(TaskAndCallback& _inst_taskandcallback, TaskImplResult* result) const;
};

static void setGluaStateScopeValue(lvm::lua::lib::GluaStateScope& scope,
                                   const std::string& str_caller,
                                   const std::string& str_caller_addr,
                                   const GluaStateValue& statevalue,
                                   const size_t limit_num
                                  );
#endif
