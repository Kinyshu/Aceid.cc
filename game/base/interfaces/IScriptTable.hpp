#pragma once

#ifndef ISCRIPTTABLE_HPP
#define ISCRIPTTABLE_HPP

#include "../structures/ScriptAnyValue.hpp"

interface IScriptTable {

	struct Iterator {
		const char* sKey;
		int nKey;
		ScriptAnyValue value;
		ScriptAnyValue key;
		//Iterator::<unnamed_type_internal> internal;
	};

	const struct SUserFunctionDesc {

		const char* sFunctionName;
		const char* sFunctionParams;
		const char* sGlobalName;
		//Functor1wRet<IFunctionHandler*, int> pFunctor;
		int nParamIdOffset;
		//int(__fastcall* pUserDataFunc)(IFunctionHandler*, void*, int);
		void* pDataBuffer;
		int nDataSize;
	};

	virtual void DIScriptTable();
	virtual interface IScriptSystem* GetScriptSystem();
	virtual void AddRef();
	virtual void Release();
	virtual void Delegate(IScriptTable* pMetatable);
	virtual void* GetUserDataValue();
	virtual void SetValueAny(const char* sKey, const ScriptAnyValue* any, bool bChain);
	virtual bool GetValueAny(const char* sKey, ScriptAnyValue* any, bool bChain);
	virtual bool BeginSetGetChain();
	virtual void EndSetGetChain();
	virtual ScriptVarType GetValueType(const char* sKey);
	virtual ScriptVarType GetAtType(int nIdx);
	virtual void SetAtAny(int nIndex, const ScriptAnyValue* any);
	virtual bool GetAtAny(int nIndex, ScriptAnyValue* any);
	virtual Iterator* BeginIteration(Iterator* result, bool resolvePrototypeTableAsWell);
	virtual bool MoveNext(IScriptTable::Iterator* iter);
	virtual void EndIteration(const IScriptTable::Iterator* iterr);
	virtual void Clear();
	virtual int Count();
	virtual bool Clone(IScriptTable* pSrcTable, bool bDeepCopy, bool bCopyByReference);
	virtual void Dump(interface IScriptTableDumpSink* p);
	virtual bool AddFunction(const SUserFunctionDesc* fd);
};

#endif // !ISCRIPTTABLE_HPP