#pragma once
#include <string>
#include <vector>

#include "garbage_collector.h"
#include "object.h"
#include "scope.h"

class Scheme {
public:
    Scheme();

    std::string Evaluate(const std::string& expr);

    Scope* GetGlobalScope();

    ~Scheme();

private:
    Scope* global_scope_;
};

bool CheckPair(Object* ptr);

bool CheckList(Object* ptr);

Object* CalcExpression(Object* object, Scope* scope);

std::vector<Object*> Convert(Object* ptr);

// class Scheme {
// public:
//     std::string Evaluate(const std::string& expression);
//     Scope scope;
// };