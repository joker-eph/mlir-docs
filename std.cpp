/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Op Definitions                                                             *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_OP_LIST
#undef GET_OP_LIST

AddFOp,
AddIOp,
AllocOp,
AndOp,
BranchOp,
CallIndirectOp,
CallOp,
CmpFOp,
CmpIOp,
CondBranchOp,
ConstantOp,
DeallocOp,
DimOp,
DivFOp,
DivISOp,
DivIUOp,
ExtractElementOp,
IndexCastOp,
LoadOp,
MemRefCastOp,
MulFOp,
MulIOp,
OrOp,
RankOp,
RemFOp,
RemISOp,
RemIUOp,
ReturnOp,
SIToFPOp,
SelectOp,
ShlISOp,
StoreOp,
SubFOp,
SubIOp,
TensorCastOp,
TensorLoadOp,
TensorStoreOp,
XOrOp
#endif  // GET_OP_LIST

#ifdef GET_OP_CLASSES
#undef GET_OP_CLASSES


//===----------------------------------------------------------------------===//
// AddFOp definitions
//===----------------------------------------------------------------------===//

AddFOpOperandAdaptor::AddFOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> AddFOpOperandAdaptor::getODSOperands(unsigned index) {
return {std::next(tblgen_operands.begin(), index), std::next(tblgen_operands.begin(), index + 1)};
}

Value *AddFOpOperandAdaptor::lhs() {
return *getODSOperands(0).begin();
}

Value *AddFOpOperandAdaptor::rhs() {
return *getODSOperands(1).begin();
}

StringRef AddFOp::getOperationName() {
  return "std.addf";
}

Operation::operand_range AddFOp::getODSOperands(unsigned index) {
return {std::next(getOperation()->operand_begin(), index), std::next(getOperation()->operand_begin(), index + 1)};
}

Value *AddFOp::lhs() {
return *getODSOperands(0).begin();
}

Value *AddFOp::rhs() {
return *getODSOperands(1).begin();
}

Operation::result_range AddFOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

void AddFOp::build(Builder *, OperationState *tblgen_state, Type resultType0, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes(resultType0);
}

void AddFOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes(resultTypes);
}

void AddFOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  assert(operands.size() == 2u && "mismatched number of parameters");
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

void AddFOp::build(Builder *, OperationState *tblgen_state, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes({lhs->getType()});

}

ParseResult AddFOp::parse(OpAsmParser *parser, OperationState *result) {
  return impl::parseBinaryOp(parser, result);
}

void AddFOp::print(OpAsmPrinter *p) {
  return printStandardBinaryOp(this->getOperation(), p);
}

LogicalResult AddFOp::verify() {
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSOperands(0)) {
      (void)v;
      if (!(((v->getType().isa<FloatType>())) || (((v->getType().isa<VectorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<FloatType>()))) || (((v->getType().isa<TensorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<FloatType>()))))) {
        return emitOpError("operand #") << index << " must be floating-point-like";
      }
      ++index;
    }
    for (Value *v : getODSOperands(1)) {
      (void)v;
      if (!(((v->getType().isa<FloatType>())) || (((v->getType().isa<VectorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<FloatType>()))) || (((v->getType().isa<TensorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<FloatType>()))))) {
        return emitOpError("operand #") << index << " must be floating-point-like";
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSResults(0)) {
      (void)v;
      if (!((true))) {
        return emitOpError("result #") << index << " must be any type";
      }
      ++index;
    }
  }
  if (this->getOperation()->getNumRegions() != 0) {
    return emitOpError("has incorrect number of regions: expected 0 but found ") << this->getOperation()->getNumRegions();
  }
  return mlir::success();
}




//===----------------------------------------------------------------------===//
// AddIOp definitions
//===----------------------------------------------------------------------===//

AddIOpOperandAdaptor::AddIOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> AddIOpOperandAdaptor::getODSOperands(unsigned index) {
return {std::next(tblgen_operands.begin(), index), std::next(tblgen_operands.begin(), index + 1)};
}

Value *AddIOpOperandAdaptor::lhs() {
return *getODSOperands(0).begin();
}

Value *AddIOpOperandAdaptor::rhs() {
return *getODSOperands(1).begin();
}

StringRef AddIOp::getOperationName() {
  return "std.addi";
}

Operation::operand_range AddIOp::getODSOperands(unsigned index) {
return {std::next(getOperation()->operand_begin(), index), std::next(getOperation()->operand_begin(), index + 1)};
}

Value *AddIOp::lhs() {
return *getODSOperands(0).begin();
}

Value *AddIOp::rhs() {
return *getODSOperands(1).begin();
}

Operation::result_range AddIOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

void AddIOp::build(Builder *, OperationState *tblgen_state, Type resultType0, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes(resultType0);
}

void AddIOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes(resultTypes);
}

void AddIOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  assert(operands.size() == 2u && "mismatched number of parameters");
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

void AddIOp::build(Builder *, OperationState *tblgen_state, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes({lhs->getType()});

}

ParseResult AddIOp::parse(OpAsmParser *parser, OperationState *result) {
  return impl::parseBinaryOp(parser, result);
}

void AddIOp::print(OpAsmPrinter *p) {
  return printStandardBinaryOp(this->getOperation(), p);
}

LogicalResult AddIOp::verify() {
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSOperands(0)) {
      (void)v;
      if (!(((v->getType().isa<IntegerType>())) || ((v->getType().isa<IndexType>())) || (((v->getType().isa<VectorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))) || (((v->getType().isa<TensorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))))) {
        return emitOpError("operand #") << index << " must be integer-like";
      }
      ++index;
    }
    for (Value *v : getODSOperands(1)) {
      (void)v;
      if (!(((v->getType().isa<IntegerType>())) || ((v->getType().isa<IndexType>())) || (((v->getType().isa<VectorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))) || (((v->getType().isa<TensorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))))) {
        return emitOpError("operand #") << index << " must be integer-like";
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSResults(0)) {
      (void)v;
      if (!((true))) {
        return emitOpError("result #") << index << " must be any type";
      }
      ++index;
    }
  }
  if (this->getOperation()->getNumRegions() != 0) {
    return emitOpError("has incorrect number of regions: expected 0 but found ") << this->getOperation()->getNumRegions();
  }
  return mlir::success();
}




//===----------------------------------------------------------------------===//
// AllocOp definitions
//===----------------------------------------------------------------------===//

AllocOpOperandAdaptor::AllocOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> AllocOpOperandAdaptor::getODSOperands(unsigned index) {
  bool isVariadic[] = {true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (tblgen_operands.size() - 0) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int offset = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;

  return {std::next(tblgen_operands.begin(), offset), std::next(tblgen_operands.begin(), offset + size)};
}

ArrayRef<Value *> AllocOpOperandAdaptor::value() {
return getODSOperands(0);
}

StringRef AllocOp::getOperationName() {
  return "std.alloc";
}

Operation::operand_range AllocOp::getODSOperands(unsigned index) {
  bool isVariadic[] = {true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (getOperation()->getNumOperands() - 0) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int offset = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;

  return {std::next(getOperation()->operand_begin(), offset), std::next(getOperation()->operand_begin(), offset + size)};
}

Operation::operand_range AllocOp::value() {
return getODSOperands(0);
}

Operation::result_range AllocOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

void AllocOp::build(Builder *builder, OperationState *result, MemRefType memrefType) {
       result->types.push_back(memrefType);
     
}

void AllocOp::build(Builder *, OperationState *tblgen_state, Type resultType0, ArrayRef<Value *> value) {
  tblgen_state->addOperands(value);
  tblgen_state->addTypes(resultType0);
}

void AllocOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> value) {
  tblgen_state->addOperands(value);
  tblgen_state->addTypes(resultTypes);
}

void AllocOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

ParseResult AllocOp::parse(OpAsmParser *parser, OperationState *result) {
  return ::parseAllocOp(parser, result);
}

void AllocOp::print(OpAsmPrinter *p) {
  return ::print(p, *this);
}

LogicalResult AllocOp::verify() {
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSOperands(0)) {
      (void)v;
      if (!((v->getType().isa<IndexType>()))) {
        return emitOpError("operand #") << index << " must be index";
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSResults(0)) {
      (void)v;
      if (!(((v->getType().isa<MemRefType>())) && ((true)))) {
        return emitOpError("result #") << index << " must be memref of any type values";
      }
      ++index;
    }
  }
  if (this->getOperation()->getNumRegions() != 0) {
    return emitOpError("has incorrect number of regions: expected 0 but found ") << this->getOperation()->getNumRegions();
  }
  return ::verify(*this);
}




//===----------------------------------------------------------------------===//
// AndOp definitions
//===----------------------------------------------------------------------===//

AndOpOperandAdaptor::AndOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> AndOpOperandAdaptor::getODSOperands(unsigned index) {
return {std::next(tblgen_operands.begin(), index), std::next(tblgen_operands.begin(), index + 1)};
}

Value *AndOpOperandAdaptor::lhs() {
return *getODSOperands(0).begin();
}

Value *AndOpOperandAdaptor::rhs() {
return *getODSOperands(1).begin();
}

StringRef AndOp::getOperationName() {
  return "std.and";
}

Operation::operand_range AndOp::getODSOperands(unsigned index) {
return {std::next(getOperation()->operand_begin(), index), std::next(getOperation()->operand_begin(), index + 1)};
}

Value *AndOp::lhs() {
return *getODSOperands(0).begin();
}

Value *AndOp::rhs() {
return *getODSOperands(1).begin();
}

Operation::result_range AndOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

void AndOp::build(Builder *, OperationState *tblgen_state, Type resultType0, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes(resultType0);
}

void AndOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes(resultTypes);
}

void AndOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  assert(operands.size() == 2u && "mismatched number of parameters");
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

void AndOp::build(Builder *, OperationState *tblgen_state, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes({lhs->getType()});

}

ParseResult AndOp::parse(OpAsmParser *parser, OperationState *result) {
  return impl::parseBinaryOp(parser, result);
}

void AndOp::print(OpAsmPrinter *p) {
  return printStandardBinaryOp(this->getOperation(), p);
}

LogicalResult AndOp::verify() {
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSOperands(0)) {
      (void)v;
      if (!(((v->getType().isa<IntegerType>())) || ((v->getType().isa<IndexType>())) || (((v->getType().isa<VectorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))) || (((v->getType().isa<TensorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))))) {
        return emitOpError("operand #") << index << " must be integer-like";
      }
      ++index;
    }
    for (Value *v : getODSOperands(1)) {
      (void)v;
      if (!(((v->getType().isa<IntegerType>())) || ((v->getType().isa<IndexType>())) || (((v->getType().isa<VectorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))) || (((v->getType().isa<TensorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))))) {
        return emitOpError("operand #") << index << " must be integer-like";
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSResults(0)) {
      (void)v;
      if (!((true))) {
        return emitOpError("result #") << index << " must be any type";
      }
      ++index;
    }
  }
  if (this->getOperation()->getNumRegions() != 0) {
    return emitOpError("has incorrect number of regions: expected 0 but found ") << this->getOperation()->getNumRegions();
  }
  return mlir::success();
}




//===----------------------------------------------------------------------===//
// BranchOp definitions
//===----------------------------------------------------------------------===//

BranchOpOperandAdaptor::BranchOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> BranchOpOperandAdaptor::getODSOperands(unsigned index) {
  bool isVariadic[] = {true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (tblgen_operands.size() - 0) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int offset = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;

  return {std::next(tblgen_operands.begin(), offset), std::next(tblgen_operands.begin(), offset + size)};
}

ArrayRef<Value *> BranchOpOperandAdaptor::operands() {
return getODSOperands(0);
}

StringRef BranchOp::getOperationName() {
  return "std.br";
}

Operation::operand_range BranchOp::getODSOperands(unsigned index) {
  bool isVariadic[] = {true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (getOperation()->getNumOperands() - 0) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int offset = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;

  return {std::next(getOperation()->operand_begin(), offset), std::next(getOperation()->operand_begin(), offset + size)};
}

Operation::operand_range BranchOp::operands() {
return getODSOperands(0);
}

Operation::result_range BranchOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

void BranchOp::build(Builder *, OperationState *result, Block *dest,ArrayRef<Value *> operands ) {
      result->addSuccessor(dest, operands);
  
}

void BranchOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Value *> operands) {
  tblgen_state->addOperands(operands);
}

void BranchOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 0u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

ParseResult BranchOp::parse(OpAsmParser *parser, OperationState *result) {
  return ::parseBranchOp(parser, result);
}

void BranchOp::print(OpAsmPrinter *p) {
  return ::print(p, *this);
}

LogicalResult BranchOp::verify() {
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSOperands(0)) {
      (void)v;
      if (!((true))) {
        return emitOpError("operand #") << index << " must be any type";
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
  }
  if (this->getOperation()->getNumRegions() != 0) {
    return emitOpError("has incorrect number of regions: expected 0 but found ") << this->getOperation()->getNumRegions();
  }
  return mlir::success();
}


//===----------------------------------------------------------------------===//
// CallIndirectOp definitions
//===----------------------------------------------------------------------===//

CallIndirectOpOperandAdaptor::CallIndirectOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> CallIndirectOpOperandAdaptor::getODSOperands(unsigned index) {
  bool isVariadic[] = {false, true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (tblgen_operands.size() - 1) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int offset = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;

  return {std::next(tblgen_operands.begin(), offset), std::next(tblgen_operands.begin(), offset + size)};
}

Value *CallIndirectOpOperandAdaptor::callee() {
return *getODSOperands(0).begin();
}

ArrayRef<Value *> CallIndirectOpOperandAdaptor::operands() {
return getODSOperands(1);
}

StringRef CallIndirectOp::getOperationName() {
  return "std.call_indirect";
}

Operation::operand_range CallIndirectOp::getODSOperands(unsigned index) {
  bool isVariadic[] = {false, true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (getOperation()->getNumOperands() - 1) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int offset = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;

  return {std::next(getOperation()->operand_begin(), offset), std::next(getOperation()->operand_begin(), offset + size)};
}

Value *CallIndirectOp::callee() {
return *getODSOperands(0).begin();
}

Operation::operand_range CallIndirectOp::operands() {
return getODSOperands(1);
}

Operation::result_range CallIndirectOp::getODSResults(unsigned index) {
  bool isVariadic[] = {true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic result corresponds to.
  // This assumes all static variadic results have the same dynamic value count.
  int variadicSize = (getOperation()->getNumResults() - 0) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // result (variadic or not) as size 1. So here for each previous static variadic
  // result, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static result starts.
  int offset = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;

  return {std::next(getOperation()->result_begin(), offset), std::next(getOperation()->result_begin(), offset + size)};
}

void CallIndirectOp::build(Builder *, OperationState *result, Value *callee,ArrayRef<Value *> operands ) {
      result->operands.push_back(callee);
      result->addOperands(operands);
      result->addTypes(callee->getType().cast<FunctionType>().getResults());
  
}

void CallIndirectOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultType0, Value *callee, ArrayRef<Value *> operands) {
  tblgen_state->addOperands(callee);
  tblgen_state->addOperands(operands);
  tblgen_state->addTypes(resultType0);
}

void CallIndirectOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  tblgen_state->addTypes(resultTypes);
  assert(operands.size() >= 1u && "mismatched number of parameters");
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

ParseResult CallIndirectOp::parse(OpAsmParser *parser, OperationState *result) {
  return ::parseCallIndirectOp(parser, result);
}

void CallIndirectOp::print(OpAsmPrinter *p) {
  return ::print(p, *this);
}

LogicalResult CallIndirectOp::verify() {
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSOperands(0)) {
      (void)v;
      if (!((v->getType().isa<FunctionType>()))) {
        return emitOpError("operand #") << index << " must be function type";
      }
      ++index;
    }
    for (Value *v : getODSOperands(1)) {
      (void)v;
      if (!((true))) {
        return emitOpError("operand #") << index << " must be any type";
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSResults(0)) {
      (void)v;
      if (!((true))) {
        return emitOpError("result #") << index << " must be any type";
      }
      ++index;
    }
  }
  if (this->getOperation()->getNumRegions() != 0) {
    return emitOpError("has incorrect number of regions: expected 0 but found ") << this->getOperation()->getNumRegions();
  }
  return ::verify(*this);
}




//===----------------------------------------------------------------------===//
// CallOp definitions
//===----------------------------------------------------------------------===//

CallOpOperandAdaptor::CallOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> CallOpOperandAdaptor::getODSOperands(unsigned index) {
  bool isVariadic[] = {true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (tblgen_operands.size() - 0) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int offset = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;

  return {std::next(tblgen_operands.begin(), offset), std::next(tblgen_operands.begin(), offset + size)};
}

ArrayRef<Value *> CallOpOperandAdaptor::operands() {
return getODSOperands(0);
}

StringRef CallOp::getOperationName() {
  return "std.call";
}

Operation::operand_range CallOp::getODSOperands(unsigned index) {
  bool isVariadic[] = {true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (getOperation()->getNumOperands() - 0) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int offset = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;

  return {std::next(getOperation()->operand_begin(), offset), std::next(getOperation()->operand_begin(), offset + size)};
}

Operation::operand_range CallOp::operands() {
return getODSOperands(0);
}

Operation::result_range CallOp::getODSResults(unsigned index) {
  bool isVariadic[] = {true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic result corresponds to.
  // This assumes all static variadic results have the same dynamic value count.
  int variadicSize = (getOperation()->getNumResults() - 0) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // result (variadic or not) as size 1. So here for each previous static variadic
  // result, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static result starts.
  int offset = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;

  return {std::next(getOperation()->result_begin(), offset), std::next(getOperation()->result_begin(), offset + size)};
}

StringRef CallOp::callee() {
  auto attr = this->getAttr("callee").cast<SymbolRefAttr>();
  return attr.getValue();
}

void CallOp::build(Builder *builder, OperationState *result, FuncOp callee,ArrayRef<Value *> operands ) {
      result->addOperands(operands);
      result->addAttribute("callee", builder->getSymbolRefAttr(callee));
      result->addTypes(callee.getType().getResults());
  
}

void CallOp::build(Builder *builder, OperationState *result, StringRef callee,ArrayRef<Type> results, ArrayRef<Value *> operands ) {
      result->addOperands(operands);
      result->addAttribute("callee", builder->getSymbolRefAttr(callee));
      result->addTypes(results);
  
}

void CallOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultType0, SymbolRefAttr callee, ArrayRef<Value *> operands) {
  tblgen_state->addOperands(operands);
  tblgen_state->addAttribute("callee", callee);
  tblgen_state->addTypes(resultType0);
}

void CallOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  tblgen_state->addTypes(resultTypes);
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

ParseResult CallOp::parse(OpAsmParser *parser, OperationState *result) {
  return ::parseCallOp(parser, result);
}

void CallOp::print(OpAsmPrinter *p) {
  return ::print(p, *this);
}

LogicalResult CallOp::verify() {
  auto tblgen_callee = this->getAttr("callee");
  if (!tblgen_callee) return emitOpError("requires attribute 'callee'");
  {
    if (!((tblgen_callee.isa<SymbolRefAttr>()))) return emitOpError("attribute 'callee' failed to satisfy constraint: symbol reference attribute");
  }
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSOperands(0)) {
      (void)v;
      if (!((true))) {
        return emitOpError("operand #") << index << " must be any type";
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSResults(0)) {
      (void)v;
      if (!((true))) {
        return emitOpError("result #") << index << " must be any type";
      }
      ++index;
    }
  }
  if (this->getOperation()->getNumRegions() != 0) {
    return emitOpError("has incorrect number of regions: expected 0 but found ") << this->getOperation()->getNumRegions();
  }
  return ::verify(*this);
}


//===----------------------------------------------------------------------===//
// CmpFOp definitions
//===----------------------------------------------------------------------===//

CmpFOpOperandAdaptor::CmpFOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> CmpFOpOperandAdaptor::getODSOperands(unsigned index) {
return {std::next(tblgen_operands.begin(), index), std::next(tblgen_operands.begin(), index + 1)};
}

Value *CmpFOpOperandAdaptor::lhs() {
return *getODSOperands(0).begin();
}

Value *CmpFOpOperandAdaptor::rhs() {
return *getODSOperands(1).begin();
}

StringRef CmpFOp::getOperationName() {
  return "std.cmpf";
}

Operation::operand_range CmpFOp::getODSOperands(unsigned index) {
return {std::next(getOperation()->operand_begin(), index), std::next(getOperation()->operand_begin(), index + 1)};
}

Value *CmpFOp::lhs() {
return *getODSOperands(0).begin();
}

Value *CmpFOp::rhs() {
return *getODSOperands(1).begin();
}

Operation::result_range CmpFOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

void CmpFOp::build(Builder *builder, OperationState *result, CmpFPredicate predicate,Value *lhs, Value *rhs) {
      ::buildCmpFOp(builder, result, predicate, lhs, rhs);
  
}

void CmpFOp::build(Builder *, OperationState *tblgen_state, Type resultType0, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes(resultType0);
}

void CmpFOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes(resultTypes);
}

void CmpFOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  assert(operands.size() == 2u && "mismatched number of parameters");
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

ParseResult CmpFOp::parse(OpAsmParser *parser, OperationState *result) {
  return ::parseCmpFOp(parser, result);
}

void CmpFOp::print(OpAsmPrinter *p) {
  return ::print(p, *this);
}

LogicalResult CmpFOp::verify() {
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSOperands(0)) {
      (void)v;
      if (!(((v->getType().isa<FloatType>())) || (((v->getType().isa<VectorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<FloatType>()))) || (((v->getType().isa<TensorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<FloatType>()))))) {
        return emitOpError("operand #") << index << " must be floating-point-like";
      }
      ++index;
    }
    for (Value *v : getODSOperands(1)) {
      (void)v;
      if (!(((v->getType().isa<FloatType>())) || (((v->getType().isa<VectorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<FloatType>()))) || (((v->getType().isa<TensorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<FloatType>()))))) {
        return emitOpError("operand #") << index << " must be floating-point-like";
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSResults(0)) {
      (void)v;
      if (!(((v->getType().isInteger(1))) || (((v->getType().isa<VectorType>())) && ((v->getType().cast<ShapedType>().getElementType().isInteger(1)))) || (((v->getType().isa<TensorType>())) && ((v->getType().cast<ShapedType>().getElementType().isInteger(1)))))) {
        return emitOpError("result #") << index << " must be bool-like";
      }
      ++index;
    }
  }
  if (this->getOperation()->getNumRegions() != 0) {
    return emitOpError("has incorrect number of regions: expected 0 but found ") << this->getOperation()->getNumRegions();
  }
  return ::verify(*this);
}




//===----------------------------------------------------------------------===//
// CmpIOp definitions
//===----------------------------------------------------------------------===//

CmpIOpOperandAdaptor::CmpIOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> CmpIOpOperandAdaptor::getODSOperands(unsigned index) {
return {std::next(tblgen_operands.begin(), index), std::next(tblgen_operands.begin(), index + 1)};
}

Value *CmpIOpOperandAdaptor::lhs() {
return *getODSOperands(0).begin();
}

Value *CmpIOpOperandAdaptor::rhs() {
return *getODSOperands(1).begin();
}

StringRef CmpIOp::getOperationName() {
  return "std.cmpi";
}

Operation::operand_range CmpIOp::getODSOperands(unsigned index) {
return {std::next(getOperation()->operand_begin(), index), std::next(getOperation()->operand_begin(), index + 1)};
}

Value *CmpIOp::lhs() {
return *getODSOperands(0).begin();
}

Value *CmpIOp::rhs() {
return *getODSOperands(1).begin();
}

Operation::result_range CmpIOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

void CmpIOp::build(Builder *builder, OperationState *result, CmpIPredicate predicate,Value *lhs, Value *rhs) {
      ::buildCmpIOp(builder, result, predicate, lhs, rhs);
  
}

void CmpIOp::build(Builder *, OperationState *tblgen_state, Type resultType0, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes(resultType0);
}

void CmpIOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes(resultTypes);
}

void CmpIOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  assert(operands.size() == 2u && "mismatched number of parameters");
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

ParseResult CmpIOp::parse(OpAsmParser *parser, OperationState *result) {
  return ::parseCmpIOp(parser, result);
}

void CmpIOp::print(OpAsmPrinter *p) {
  return ::print(p, *this);
}

LogicalResult CmpIOp::verify() {
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSOperands(0)) {
      (void)v;
      if (!(((v->getType().isa<IntegerType>())) || ((v->getType().isa<IndexType>())) || (((v->getType().isa<VectorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))) || (((v->getType().isa<TensorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))))) {
        return emitOpError("operand #") << index << " must be integer-like";
      }
      ++index;
    }
    for (Value *v : getODSOperands(1)) {
      (void)v;
      if (!(((v->getType().isa<IntegerType>())) || ((v->getType().isa<IndexType>())) || (((v->getType().isa<VectorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))) || (((v->getType().isa<TensorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))))) {
        return emitOpError("operand #") << index << " must be integer-like";
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSResults(0)) {
      (void)v;
      if (!(((v->getType().isInteger(1))) || (((v->getType().isa<VectorType>())) && ((v->getType().cast<ShapedType>().getElementType().isInteger(1)))) || (((v->getType().isa<TensorType>())) && ((v->getType().cast<ShapedType>().getElementType().isInteger(1)))))) {
        return emitOpError("result #") << index << " must be bool-like";
      }
      ++index;
    }
  }
  if (this->getOperation()->getNumRegions() != 0) {
    return emitOpError("has incorrect number of regions: expected 0 but found ") << this->getOperation()->getNumRegions();
  }
  return ::verify(*this);
}




//===----------------------------------------------------------------------===//
// CondBranchOp definitions
//===----------------------------------------------------------------------===//

CondBranchOpOperandAdaptor::CondBranchOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> CondBranchOpOperandAdaptor::getODSOperands(unsigned index) {
  bool isVariadic[] = {false, true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (tblgen_operands.size() - 1) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int offset = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;

  return {std::next(tblgen_operands.begin(), offset), std::next(tblgen_operands.begin(), offset + size)};
}

Value *CondBranchOpOperandAdaptor::condition() {
return *getODSOperands(0).begin();
}

ArrayRef<Value *> CondBranchOpOperandAdaptor::branchOperands() {
return getODSOperands(1);
}

StringRef CondBranchOp::getOperationName() {
  return "std.cond_br";
}

Operation::operand_range CondBranchOp::getODSOperands(unsigned index) {
  bool isVariadic[] = {false, true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (getOperation()->getNumOperands() - 1) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int offset = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;

  return {std::next(getOperation()->operand_begin(), offset), std::next(getOperation()->operand_begin(), offset + size)};
}

Value *CondBranchOp::condition() {
return *getODSOperands(0).begin();
}

Operation::operand_range CondBranchOp::branchOperands() {
return getODSOperands(1);
}

Operation::result_range CondBranchOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

void CondBranchOp::build(Builder *, OperationState *result, Value *condition,Block *trueDest, ArrayRef<Value *> trueOperands,Block *falseDest, ArrayRef<Value *> falseOperands) {
      result->addOperands(condition);
      result->addSuccessor(trueDest, trueOperands);
      result->addSuccessor(falseDest, falseOperands);
  
}

void CondBranchOp::build(Builder *, OperationState *tblgen_state, Value *condition, ArrayRef<Value *> branchOperands) {
  tblgen_state->addOperands(condition);
  tblgen_state->addOperands(branchOperands);
}

void CondBranchOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 0u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  assert(operands.size() >= 1u && "mismatched number of parameters");
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

ParseResult CondBranchOp::parse(OpAsmParser *parser, OperationState *result) {
  return ::parseCondBranchOp(parser, result);
}

void CondBranchOp::print(OpAsmPrinter *p) {
  return ::print(p, *this);
}

LogicalResult CondBranchOp::verify() {
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSOperands(0)) {
      (void)v;
      if (!((v->getType().isInteger(1)))) {
        return emitOpError("operand #") << index << " must be 1-bit integer";
      }
      ++index;
    }
    for (Value *v : getODSOperands(1)) {
      (void)v;
      if (!((true))) {
        return emitOpError("operand #") << index << " must be any type";
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
  }
  if (this->getOperation()->getNumRegions() != 0) {
    return emitOpError("has incorrect number of regions: expected 0 but found ") << this->getOperation()->getNumRegions();
  }
  return mlir::success();
}




//===----------------------------------------------------------------------===//
// ConstantOp definitions
//===----------------------------------------------------------------------===//

ConstantOpOperandAdaptor::ConstantOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> ConstantOpOperandAdaptor::getODSOperands(unsigned index) {
return {std::next(tblgen_operands.begin(), index), std::next(tblgen_operands.begin(), index + 1)};
}

StringRef ConstantOp::getOperationName() {
  return "std.constant";
}

Operation::operand_range ConstantOp::getODSOperands(unsigned index) {
return {std::next(getOperation()->operand_begin(), index), std::next(getOperation()->operand_begin(), index + 1)};
}

Operation::result_range ConstantOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

Attribute ConstantOp::value() {
  auto attr = this->getAttr("value").cast<Attribute>();
  return attr;
}

void ConstantOp::build(Builder *builder, OperationState *result, Attribute value) {
 build(builder, result, value.getType(), value); 
}

void ConstantOp::build(Builder *, OperationState *tblgen_state, Type resultType0, Attribute value) {
  tblgen_state->addAttribute("value", value);
  tblgen_state->addTypes(resultType0);
}

void ConstantOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Attribute value) {
  tblgen_state->addAttribute("value", value);
  tblgen_state->addTypes(resultTypes);
}

void ConstantOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  assert(operands.size() == 0u && "mismatched number of parameters");
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

ParseResult ConstantOp::parse(OpAsmParser *parser, OperationState *result) {
  return ::parseConstantOp(parser, result);
}

void ConstantOp::print(OpAsmPrinter *p) {
  return ::print(p, *this);
}

LogicalResult ConstantOp::verify() {
  auto tblgen_value = this->getAttr("value");
  if (!tblgen_value) return emitOpError("requires attribute 'value'");
  {
    if (!((true))) return emitOpError("attribute 'value' failed to satisfy constraint: any attribute");
  }
  {
    unsigned index = 0; (void)index;
  }
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSResults(0)) {
      (void)v;
      if (!((true))) {
        return emitOpError("result #") << index << " must be any type";
      }
      ++index;
    }
  }
  if (this->getOperation()->getNumRegions() != 0) {
    return emitOpError("has incorrect number of regions: expected 0 but found ") << this->getOperation()->getNumRegions();
  }
  return ::verify(*this);
}




//===----------------------------------------------------------------------===//
// DeallocOp definitions
//===----------------------------------------------------------------------===//

DeallocOpOperandAdaptor::DeallocOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> DeallocOpOperandAdaptor::getODSOperands(unsigned index) {
return {std::next(tblgen_operands.begin(), index), std::next(tblgen_operands.begin(), index + 1)};
}

Value *DeallocOpOperandAdaptor::memref() {
return *getODSOperands(0).begin();
}

StringRef DeallocOp::getOperationName() {
  return "std.dealloc";
}

Operation::operand_range DeallocOp::getODSOperands(unsigned index) {
return {std::next(getOperation()->operand_begin(), index), std::next(getOperation()->operand_begin(), index + 1)};
}

Value *DeallocOp::memref() {
return *getODSOperands(0).begin();
}

Operation::result_range DeallocOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

void DeallocOp::build(Builder *, OperationState *tblgen_state, Value *memref) {
  tblgen_state->addOperands(memref);
}

void DeallocOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 0u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  assert(operands.size() == 1u && "mismatched number of parameters");
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

ParseResult DeallocOp::parse(OpAsmParser *parser, OperationState *result) {
  return ::parseDeallocOp(parser, result);
}

void DeallocOp::print(OpAsmPrinter *p) {
  return ::print(p, *this);
}

LogicalResult DeallocOp::verify() {
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSOperands(0)) {
      (void)v;
      if (!(((v->getType().isa<MemRefType>())) && ((true)))) {
        return emitOpError("operand #") << index << " must be memref of any type values";
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
  }
  if (this->getOperation()->getNumRegions() != 0) {
    return emitOpError("has incorrect number of regions: expected 0 but found ") << this->getOperation()->getNumRegions();
  }
  return ::verify(*this);
}




//===----------------------------------------------------------------------===//
// DimOp definitions
//===----------------------------------------------------------------------===//

DimOpOperandAdaptor::DimOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> DimOpOperandAdaptor::getODSOperands(unsigned index) {
return {std::next(tblgen_operands.begin(), index), std::next(tblgen_operands.begin(), index + 1)};
}

Value *DimOpOperandAdaptor::memrefOrTensor() {
return *getODSOperands(0).begin();
}

StringRef DimOp::getOperationName() {
  return "std.dim";
}

Operation::operand_range DimOp::getODSOperands(unsigned index) {
return {std::next(getOperation()->operand_begin(), index), std::next(getOperation()->operand_begin(), index + 1)};
}

Value *DimOp::memrefOrTensor() {
return *getODSOperands(0).begin();
}

Operation::result_range DimOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

APInt DimOp::index() {
  auto attr = this->getAttr("index").cast<IntegerAttr>();
  return attr.getValue();
}

void DimOp::build(Builder *builder, OperationState *result, Value *memrefOrTensor,unsigned index) {
      auto indexType = builder->getIndexType();
      auto indexAttr = builder->getIntegerAttr(indexType, index);
      build(builder, result, indexType, memrefOrTensor, indexAttr);
    
}

void DimOp::build(Builder *, OperationState *tblgen_state, Type resultType0, Value *memrefOrTensor, IntegerAttr index) {
  tblgen_state->addOperands(memrefOrTensor);
  tblgen_state->addAttribute("index", index);
  tblgen_state->addTypes(resultType0);
}

void DimOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Value *memrefOrTensor, IntegerAttr index) {
  tblgen_state->addOperands(memrefOrTensor);
  tblgen_state->addAttribute("index", index);
  tblgen_state->addTypes(resultTypes);
}

void DimOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  assert(operands.size() == 1u && "mismatched number of parameters");
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

ParseResult DimOp::parse(OpAsmParser *parser, OperationState *result) {
  return ::parseDimOp(parser, result);
}

void DimOp::print(OpAsmPrinter *p) {
  return ::print(p, *this);
}

LogicalResult DimOp::verify() {
  auto tblgen_index = this->getAttr("index");
  if (!tblgen_index) return emitOpError("requires attribute 'index'");
  {
    if (!((tblgen_index.isa<IntegerAttr>()))) return emitOpError("attribute 'index' failed to satisfy constraint: arbitrary integer attribute");
  }
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSOperands(0)) {
      (void)v;
      if (!((((v->getType().isa<MemRefType>())) && ((true))) || (((v->getType().isa<TensorType>())) && ((true))))) {
        return emitOpError("operand #") << index << " must be any tensor or memref type";
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSResults(0)) {
      (void)v;
      if (!((v->getType().isa<IndexType>()))) {
        return emitOpError("result #") << index << " must be index";
      }
      ++index;
    }
  }
  if (this->getOperation()->getNumRegions() != 0) {
    return emitOpError("has incorrect number of regions: expected 0 but found ") << this->getOperation()->getNumRegions();
  }
  return ::verify(*this);
}




//===----------------------------------------------------------------------===//
// DivFOp definitions
//===----------------------------------------------------------------------===//

DivFOpOperandAdaptor::DivFOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> DivFOpOperandAdaptor::getODSOperands(unsigned index) {
return {std::next(tblgen_operands.begin(), index), std::next(tblgen_operands.begin(), index + 1)};
}

Value *DivFOpOperandAdaptor::lhs() {
return *getODSOperands(0).begin();
}

Value *DivFOpOperandAdaptor::rhs() {
return *getODSOperands(1).begin();
}

StringRef DivFOp::getOperationName() {
  return "std.divf";
}

Operation::operand_range DivFOp::getODSOperands(unsigned index) {
return {std::next(getOperation()->operand_begin(), index), std::next(getOperation()->operand_begin(), index + 1)};
}

Value *DivFOp::lhs() {
return *getODSOperands(0).begin();
}

Value *DivFOp::rhs() {
return *getODSOperands(1).begin();
}

Operation::result_range DivFOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

void DivFOp::build(Builder *, OperationState *tblgen_state, Type resultType0, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes(resultType0);
}

void DivFOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes(resultTypes);
}

void DivFOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  assert(operands.size() == 2u && "mismatched number of parameters");
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

void DivFOp::build(Builder *, OperationState *tblgen_state, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes({lhs->getType()});

}

ParseResult DivFOp::parse(OpAsmParser *parser, OperationState *result) {
  return impl::parseBinaryOp(parser, result);
}

void DivFOp::print(OpAsmPrinter *p) {
  return printStandardBinaryOp(this->getOperation(), p);
}

LogicalResult DivFOp::verify() {
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSOperands(0)) {
      (void)v;
      if (!(((v->getType().isa<FloatType>())) || (((v->getType().isa<VectorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<FloatType>()))) || (((v->getType().isa<TensorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<FloatType>()))))) {
        return emitOpError("operand #") << index << " must be floating-point-like";
      }
      ++index;
    }
    for (Value *v : getODSOperands(1)) {
      (void)v;
      if (!(((v->getType().isa<FloatType>())) || (((v->getType().isa<VectorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<FloatType>()))) || (((v->getType().isa<TensorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<FloatType>()))))) {
        return emitOpError("operand #") << index << " must be floating-point-like";
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSResults(0)) {
      (void)v;
      if (!((true))) {
        return emitOpError("result #") << index << " must be any type";
      }
      ++index;
    }
  }
  if (this->getOperation()->getNumRegions() != 0) {
    return emitOpError("has incorrect number of regions: expected 0 but found ") << this->getOperation()->getNumRegions();
  }
  return mlir::success();
}


//===----------------------------------------------------------------------===//
// DivISOp definitions
//===----------------------------------------------------------------------===//

DivISOpOperandAdaptor::DivISOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> DivISOpOperandAdaptor::getODSOperands(unsigned index) {
return {std::next(tblgen_operands.begin(), index), std::next(tblgen_operands.begin(), index + 1)};
}

Value *DivISOpOperandAdaptor::lhs() {
return *getODSOperands(0).begin();
}

Value *DivISOpOperandAdaptor::rhs() {
return *getODSOperands(1).begin();
}

StringRef DivISOp::getOperationName() {
  return "std.divis";
}

Operation::operand_range DivISOp::getODSOperands(unsigned index) {
return {std::next(getOperation()->operand_begin(), index), std::next(getOperation()->operand_begin(), index + 1)};
}

Value *DivISOp::lhs() {
return *getODSOperands(0).begin();
}

Value *DivISOp::rhs() {
return *getODSOperands(1).begin();
}

Operation::result_range DivISOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

void DivISOp::build(Builder *, OperationState *tblgen_state, Type resultType0, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes(resultType0);
}

void DivISOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes(resultTypes);
}

void DivISOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  assert(operands.size() == 2u && "mismatched number of parameters");
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

void DivISOp::build(Builder *, OperationState *tblgen_state, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes({lhs->getType()});

}

ParseResult DivISOp::parse(OpAsmParser *parser, OperationState *result) {
  return impl::parseBinaryOp(parser, result);
}

void DivISOp::print(OpAsmPrinter *p) {
  return printStandardBinaryOp(this->getOperation(), p);
}

LogicalResult DivISOp::verify() {
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSOperands(0)) {
      (void)v;
      if (!(((v->getType().isa<IntegerType>())) || ((v->getType().isa<IndexType>())) || (((v->getType().isa<VectorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))) || (((v->getType().isa<TensorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))))) {
        return emitOpError("operand #") << index << " must be integer-like";
      }
      ++index;
    }
    for (Value *v : getODSOperands(1)) {
      (void)v;
      if (!(((v->getType().isa<IntegerType>())) || ((v->getType().isa<IndexType>())) || (((v->getType().isa<VectorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))) || (((v->getType().isa<TensorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))))) {
        return emitOpError("operand #") << index << " must be integer-like";
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSResults(0)) {
      (void)v;
      if (!((true))) {
        return emitOpError("result #") << index << " must be any type";
      }
      ++index;
    }
  }
  if (this->getOperation()->getNumRegions() != 0) {
    return emitOpError("has incorrect number of regions: expected 0 but found ") << this->getOperation()->getNumRegions();
  }
  return mlir::success();
}




//===----------------------------------------------------------------------===//
// DivIUOp definitions
//===----------------------------------------------------------------------===//

DivIUOpOperandAdaptor::DivIUOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> DivIUOpOperandAdaptor::getODSOperands(unsigned index) {
return {std::next(tblgen_operands.begin(), index), std::next(tblgen_operands.begin(), index + 1)};
}

Value *DivIUOpOperandAdaptor::lhs() {
return *getODSOperands(0).begin();
}

Value *DivIUOpOperandAdaptor::rhs() {
return *getODSOperands(1).begin();
}

StringRef DivIUOp::getOperationName() {
  return "std.diviu";
}

Operation::operand_range DivIUOp::getODSOperands(unsigned index) {
return {std::next(getOperation()->operand_begin(), index), std::next(getOperation()->operand_begin(), index + 1)};
}

Value *DivIUOp::lhs() {
return *getODSOperands(0).begin();
}

Value *DivIUOp::rhs() {
return *getODSOperands(1).begin();
}

Operation::result_range DivIUOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

void DivIUOp::build(Builder *, OperationState *tblgen_state, Type resultType0, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes(resultType0);
}

void DivIUOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes(resultTypes);
}

void DivIUOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  assert(operands.size() == 2u && "mismatched number of parameters");
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

void DivIUOp::build(Builder *, OperationState *tblgen_state, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes({lhs->getType()});

}

ParseResult DivIUOp::parse(OpAsmParser *parser, OperationState *result) {
  return impl::parseBinaryOp(parser, result);
}

void DivIUOp::print(OpAsmPrinter *p) {
  return printStandardBinaryOp(this->getOperation(), p);
}

LogicalResult DivIUOp::verify() {
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSOperands(0)) {
      (void)v;
      if (!(((v->getType().isa<IntegerType>())) || ((v->getType().isa<IndexType>())) || (((v->getType().isa<VectorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))) || (((v->getType().isa<TensorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))))) {
        return emitOpError("operand #") << index << " must be integer-like";
      }
      ++index;
    }
    for (Value *v : getODSOperands(1)) {
      (void)v;
      if (!(((v->getType().isa<IntegerType>())) || ((v->getType().isa<IndexType>())) || (((v->getType().isa<VectorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))) || (((v->getType().isa<TensorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))))) {
        return emitOpError("operand #") << index << " must be integer-like";
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSResults(0)) {
      (void)v;
      if (!((true))) {
        return emitOpError("result #") << index << " must be any type";
      }
      ++index;
    }
  }
  if (this->getOperation()->getNumRegions() != 0) {
    return emitOpError("has incorrect number of regions: expected 0 but found ") << this->getOperation()->getNumRegions();
  }
  return mlir::success();
}




//===----------------------------------------------------------------------===//
// ExtractElementOp definitions
//===----------------------------------------------------------------------===//

ExtractElementOpOperandAdaptor::ExtractElementOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> ExtractElementOpOperandAdaptor::getODSOperands(unsigned index) {
  bool isVariadic[] = {false, true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (tblgen_operands.size() - 1) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int offset = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;

  return {std::next(tblgen_operands.begin(), offset), std::next(tblgen_operands.begin(), offset + size)};
}

Value *ExtractElementOpOperandAdaptor::aggregate() {
return *getODSOperands(0).begin();
}

ArrayRef<Value *> ExtractElementOpOperandAdaptor::indices() {
return getODSOperands(1);
}

StringRef ExtractElementOp::getOperationName() {
  return "std.extract_element";
}

Operation::operand_range ExtractElementOp::getODSOperands(unsigned index) {
  bool isVariadic[] = {false, true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (getOperation()->getNumOperands() - 1) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int offset = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;

  return {std::next(getOperation()->operand_begin(), offset), std::next(getOperation()->operand_begin(), offset + size)};
}

Value *ExtractElementOp::aggregate() {
return *getODSOperands(0).begin();
}

Operation::operand_range ExtractElementOp::indices() {
return getODSOperands(1);
}

Operation::result_range ExtractElementOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

void ExtractElementOp::build(Builder *builder, OperationState *result, Value *aggregate,ArrayRef<Value *> indices ) {
      auto resType = aggregate->getType().cast<ShapedType>()
                                         .getElementType();
      build(builder, result, resType, aggregate, indices);
    
}

void ExtractElementOp::build(Builder *, OperationState *tblgen_state, Type resultType0, Value *aggregate, ArrayRef<Value *> indices) {
  tblgen_state->addOperands(aggregate);
  tblgen_state->addOperands(indices);
  tblgen_state->addTypes(resultType0);
}

void ExtractElementOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Value *aggregate, ArrayRef<Value *> indices) {
  tblgen_state->addOperands(aggregate);
  tblgen_state->addOperands(indices);
  tblgen_state->addTypes(resultTypes);
}

void ExtractElementOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  assert(operands.size() >= 1u && "mismatched number of parameters");
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

ParseResult ExtractElementOp::parse(OpAsmParser *parser, OperationState *result) {
  return ::parseExtractElementOp(parser, result);
}

void ExtractElementOp::print(OpAsmPrinter *p) {
  return ::print(p, *this);
}

LogicalResult ExtractElementOp::verify() {
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSOperands(0)) {
      (void)v;
      if (!((((v->getType().isa<VectorType>())) && ((true))) || (((v->getType().isa<TensorType>())) && ((true))))) {
        return emitOpError("operand #") << index << " must be vector of any type values or tensor of any type values";
      }
      ++index;
    }
    for (Value *v : getODSOperands(1)) {
      (void)v;
      if (!((v->getType().isa<IndexType>()))) {
        return emitOpError("operand #") << index << " must be index";
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSResults(0)) {
      (void)v;
      if (!((true))) {
        return emitOpError("result #") << index << " must be any type";
      }
      ++index;
    }
  }
  if (this->getOperation()->getNumRegions() != 0) {
    return emitOpError("has incorrect number of regions: expected 0 but found ") << this->getOperation()->getNumRegions();
  }
  return ::verify(*this);
}




//===----------------------------------------------------------------------===//
// IndexCastOp definitions
//===----------------------------------------------------------------------===//

IndexCastOpOperandAdaptor::IndexCastOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> IndexCastOpOperandAdaptor::getODSOperands(unsigned index) {
return {std::next(tblgen_operands.begin(), index), std::next(tblgen_operands.begin(), index + 1)};
}

Value *IndexCastOpOperandAdaptor::in() {
return *getODSOperands(0).begin();
}

StringRef IndexCastOp::getOperationName() {
  return "std.index_cast";
}

Operation::operand_range IndexCastOp::getODSOperands(unsigned index) {
return {std::next(getOperation()->operand_begin(), index), std::next(getOperation()->operand_begin(), index + 1)};
}

Value *IndexCastOp::in() {
return *getODSOperands(0).begin();
}

Operation::result_range IndexCastOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

void IndexCastOp::build(Builder *builder, OperationState *result, Value *source, Type destType) {
       impl::buildCastOp(builder, result, source, destType);
  
}

void IndexCastOp::build(Builder *, OperationState *tblgen_state, Type resultType0, Value *in) {
  tblgen_state->addOperands(in);
  tblgen_state->addTypes(resultType0);
}

void IndexCastOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Value *in) {
  tblgen_state->addOperands(in);
  tblgen_state->addTypes(resultTypes);
}

void IndexCastOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  assert(operands.size() == 1u && "mismatched number of parameters");
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

ParseResult IndexCastOp::parse(OpAsmParser *parser, OperationState *result) {
  return impl::parseCastOp(parser, result);
}

void IndexCastOp::print(OpAsmPrinter *p) {
  return printStandardCastOp(this->getOperation(), p);
}

LogicalResult IndexCastOp::verify() {
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSOperands(0)) {
      (void)v;
      if (!((true))) {
        return emitOpError("operand #") << index << " must be any type";
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSResults(0)) {
      (void)v;
      if (!((true))) {
        return emitOpError("result #") << index << " must be any type";
      }
      ++index;
    }
  }
  if (this->getOperation()->getNumRegions() != 0) {
    return emitOpError("has incorrect number of regions: expected 0 but found ") << this->getOperation()->getNumRegions();
  }
  return ::verifyCastOp(*this);
}


//===----------------------------------------------------------------------===//
// LoadOp definitions
//===----------------------------------------------------------------------===//

LoadOpOperandAdaptor::LoadOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> LoadOpOperandAdaptor::getODSOperands(unsigned index) {
  bool isVariadic[] = {false, true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (tblgen_operands.size() - 1) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int offset = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;

  return {std::next(tblgen_operands.begin(), offset), std::next(tblgen_operands.begin(), offset + size)};
}

Value *LoadOpOperandAdaptor::memref() {
return *getODSOperands(0).begin();
}

ArrayRef<Value *> LoadOpOperandAdaptor::indices() {
return getODSOperands(1);
}

StringRef LoadOp::getOperationName() {
  return "std.load";
}

Operation::operand_range LoadOp::getODSOperands(unsigned index) {
  bool isVariadic[] = {false, true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (getOperation()->getNumOperands() - 1) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int offset = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;

  return {std::next(getOperation()->operand_begin(), offset), std::next(getOperation()->operand_begin(), offset + size)};
}

Value *LoadOp::memref() {
return *getODSOperands(0).begin();
}

Operation::operand_range LoadOp::indices() {
return getODSOperands(1);
}

Operation::result_range LoadOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

void LoadOp::build(Builder *, OperationState *result, Value *memref,ArrayRef<Value *> indices ) {
      auto memrefType = memref->getType().cast<MemRefType>();
      result->addOperands(memref);
      result->addOperands(indices);
      result->types.push_back(memrefType.getElementType());
  
}

void LoadOp::build(Builder *, OperationState *tblgen_state, Type resultType0, Value *memref, ArrayRef<Value *> indices) {
  tblgen_state->addOperands(memref);
  tblgen_state->addOperands(indices);
  tblgen_state->addTypes(resultType0);
}

void LoadOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Value *memref, ArrayRef<Value *> indices) {
  tblgen_state->addOperands(memref);
  tblgen_state->addOperands(indices);
  tblgen_state->addTypes(resultTypes);
}

void LoadOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  assert(operands.size() >= 1u && "mismatched number of parameters");
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

ParseResult LoadOp::parse(OpAsmParser *parser, OperationState *result) {
  return ::parseLoadOp(parser, result);
}

void LoadOp::print(OpAsmPrinter *p) {
  return ::print(p, *this);
}

LogicalResult LoadOp::verify() {
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSOperands(0)) {
      (void)v;
      if (!(((v->getType().isa<MemRefType>())) && ((true)))) {
        return emitOpError("operand #") << index << " must be memref of any type values";
      }
      ++index;
    }
    for (Value *v : getODSOperands(1)) {
      (void)v;
      if (!((v->getType().isa<IndexType>()))) {
        return emitOpError("operand #") << index << " must be index";
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSResults(0)) {
      (void)v;
      if (!((true))) {
        return emitOpError("result #") << index << " must be any type";
      }
      ++index;
    }
  }
  if (this->getOperation()->getNumRegions() != 0) {
    return emitOpError("has incorrect number of regions: expected 0 but found ") << this->getOperation()->getNumRegions();
  }
  return ::verify(*this);
}




//===----------------------------------------------------------------------===//
// MemRefCastOp definitions
//===----------------------------------------------------------------------===//

MemRefCastOpOperandAdaptor::MemRefCastOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> MemRefCastOpOperandAdaptor::getODSOperands(unsigned index) {
return {std::next(tblgen_operands.begin(), index), std::next(tblgen_operands.begin(), index + 1)};
}

Value *MemRefCastOpOperandAdaptor::source() {
return *getODSOperands(0).begin();
}

StringRef MemRefCastOp::getOperationName() {
  return "std.memref_cast";
}

Operation::operand_range MemRefCastOp::getODSOperands(unsigned index) {
return {std::next(getOperation()->operand_begin(), index), std::next(getOperation()->operand_begin(), index + 1)};
}

Value *MemRefCastOp::source() {
return *getODSOperands(0).begin();
}

Operation::result_range MemRefCastOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

void MemRefCastOp::build(Builder *builder, OperationState *result, Value *source, Type destType) {
       impl::buildCastOp(builder, result, source, destType);
  
}

void MemRefCastOp::build(Builder *, OperationState *tblgen_state, Type resultType0, Value *source) {
  tblgen_state->addOperands(source);
  tblgen_state->addTypes(resultType0);
}

void MemRefCastOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Value *source) {
  tblgen_state->addOperands(source);
  tblgen_state->addTypes(resultTypes);
}

void MemRefCastOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  assert(operands.size() == 1u && "mismatched number of parameters");
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

ParseResult MemRefCastOp::parse(OpAsmParser *parser, OperationState *result) {
  return impl::parseCastOp(parser, result);
}

void MemRefCastOp::print(OpAsmPrinter *p) {
  return printStandardCastOp(this->getOperation(), p);
}

LogicalResult MemRefCastOp::verify() {
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSOperands(0)) {
      (void)v;
      if (!(((v->getType().isa<MemRefType>())) && ((true)))) {
        return emitOpError("operand #") << index << " must be memref of any type values";
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSResults(0)) {
      (void)v;
      if (!(((v->getType().isa<MemRefType>())) && ((true)))) {
        return emitOpError("result #") << index << " must be memref of any type values";
      }
      ++index;
    }
  }
  if (this->getOperation()->getNumRegions() != 0) {
    return emitOpError("has incorrect number of regions: expected 0 but found ") << this->getOperation()->getNumRegions();
  }
  return ::verifyCastOp(*this);
}




//===----------------------------------------------------------------------===//
// MulFOp definitions
//===----------------------------------------------------------------------===//

MulFOpOperandAdaptor::MulFOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> MulFOpOperandAdaptor::getODSOperands(unsigned index) {
return {std::next(tblgen_operands.begin(), index), std::next(tblgen_operands.begin(), index + 1)};
}

Value *MulFOpOperandAdaptor::lhs() {
return *getODSOperands(0).begin();
}

Value *MulFOpOperandAdaptor::rhs() {
return *getODSOperands(1).begin();
}

StringRef MulFOp::getOperationName() {
  return "std.mulf";
}

Operation::operand_range MulFOp::getODSOperands(unsigned index) {
return {std::next(getOperation()->operand_begin(), index), std::next(getOperation()->operand_begin(), index + 1)};
}

Value *MulFOp::lhs() {
return *getODSOperands(0).begin();
}

Value *MulFOp::rhs() {
return *getODSOperands(1).begin();
}

Operation::result_range MulFOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

void MulFOp::build(Builder *, OperationState *tblgen_state, Type resultType0, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes(resultType0);
}

void MulFOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes(resultTypes);
}

void MulFOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  assert(operands.size() == 2u && "mismatched number of parameters");
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

void MulFOp::build(Builder *, OperationState *tblgen_state, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes({lhs->getType()});

}

ParseResult MulFOp::parse(OpAsmParser *parser, OperationState *result) {
  return impl::parseBinaryOp(parser, result);
}

void MulFOp::print(OpAsmPrinter *p) {
  return printStandardBinaryOp(this->getOperation(), p);
}

LogicalResult MulFOp::verify() {
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSOperands(0)) {
      (void)v;
      if (!(((v->getType().isa<FloatType>())) || (((v->getType().isa<VectorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<FloatType>()))) || (((v->getType().isa<TensorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<FloatType>()))))) {
        return emitOpError("operand #") << index << " must be floating-point-like";
      }
      ++index;
    }
    for (Value *v : getODSOperands(1)) {
      (void)v;
      if (!(((v->getType().isa<FloatType>())) || (((v->getType().isa<VectorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<FloatType>()))) || (((v->getType().isa<TensorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<FloatType>()))))) {
        return emitOpError("operand #") << index << " must be floating-point-like";
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSResults(0)) {
      (void)v;
      if (!((true))) {
        return emitOpError("result #") << index << " must be any type";
      }
      ++index;
    }
  }
  if (this->getOperation()->getNumRegions() != 0) {
    return emitOpError("has incorrect number of regions: expected 0 but found ") << this->getOperation()->getNumRegions();
  }
  return mlir::success();
}




//===----------------------------------------------------------------------===//
// MulIOp definitions
//===----------------------------------------------------------------------===//

MulIOpOperandAdaptor::MulIOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> MulIOpOperandAdaptor::getODSOperands(unsigned index) {
return {std::next(tblgen_operands.begin(), index), std::next(tblgen_operands.begin(), index + 1)};
}

Value *MulIOpOperandAdaptor::lhs() {
return *getODSOperands(0).begin();
}

Value *MulIOpOperandAdaptor::rhs() {
return *getODSOperands(1).begin();
}

StringRef MulIOp::getOperationName() {
  return "std.muli";
}

Operation::operand_range MulIOp::getODSOperands(unsigned index) {
return {std::next(getOperation()->operand_begin(), index), std::next(getOperation()->operand_begin(), index + 1)};
}

Value *MulIOp::lhs() {
return *getODSOperands(0).begin();
}

Value *MulIOp::rhs() {
return *getODSOperands(1).begin();
}

Operation::result_range MulIOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

void MulIOp::build(Builder *, OperationState *tblgen_state, Type resultType0, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes(resultType0);
}

void MulIOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes(resultTypes);
}

void MulIOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  assert(operands.size() == 2u && "mismatched number of parameters");
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

void MulIOp::build(Builder *, OperationState *tblgen_state, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes({lhs->getType()});

}

ParseResult MulIOp::parse(OpAsmParser *parser, OperationState *result) {
  return impl::parseBinaryOp(parser, result);
}

void MulIOp::print(OpAsmPrinter *p) {
  return printStandardBinaryOp(this->getOperation(), p);
}

LogicalResult MulIOp::verify() {
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSOperands(0)) {
      (void)v;
      if (!(((v->getType().isa<IntegerType>())) || ((v->getType().isa<IndexType>())) || (((v->getType().isa<VectorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))) || (((v->getType().isa<TensorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))))) {
        return emitOpError("operand #") << index << " must be integer-like";
      }
      ++index;
    }
    for (Value *v : getODSOperands(1)) {
      (void)v;
      if (!(((v->getType().isa<IntegerType>())) || ((v->getType().isa<IndexType>())) || (((v->getType().isa<VectorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))) || (((v->getType().isa<TensorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))))) {
        return emitOpError("operand #") << index << " must be integer-like";
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSResults(0)) {
      (void)v;
      if (!((true))) {
        return emitOpError("result #") << index << " must be any type";
      }
      ++index;
    }
  }
  if (this->getOperation()->getNumRegions() != 0) {
    return emitOpError("has incorrect number of regions: expected 0 but found ") << this->getOperation()->getNumRegions();
  }
  return mlir::success();
}




//===----------------------------------------------------------------------===//
// OrOp definitions
//===----------------------------------------------------------------------===//

OrOpOperandAdaptor::OrOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> OrOpOperandAdaptor::getODSOperands(unsigned index) {
return {std::next(tblgen_operands.begin(), index), std::next(tblgen_operands.begin(), index + 1)};
}

Value *OrOpOperandAdaptor::lhs() {
return *getODSOperands(0).begin();
}

Value *OrOpOperandAdaptor::rhs() {
return *getODSOperands(1).begin();
}

StringRef OrOp::getOperationName() {
  return "std.or";
}

Operation::operand_range OrOp::getODSOperands(unsigned index) {
return {std::next(getOperation()->operand_begin(), index), std::next(getOperation()->operand_begin(), index + 1)};
}

Value *OrOp::lhs() {
return *getODSOperands(0).begin();
}

Value *OrOp::rhs() {
return *getODSOperands(1).begin();
}

Operation::result_range OrOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

void OrOp::build(Builder *, OperationState *tblgen_state, Type resultType0, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes(resultType0);
}

void OrOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes(resultTypes);
}

void OrOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  assert(operands.size() == 2u && "mismatched number of parameters");
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

void OrOp::build(Builder *, OperationState *tblgen_state, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes({lhs->getType()});

}

ParseResult OrOp::parse(OpAsmParser *parser, OperationState *result) {
  return impl::parseBinaryOp(parser, result);
}

void OrOp::print(OpAsmPrinter *p) {
  return printStandardBinaryOp(this->getOperation(), p);
}

LogicalResult OrOp::verify() {
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSOperands(0)) {
      (void)v;
      if (!(((v->getType().isa<IntegerType>())) || ((v->getType().isa<IndexType>())) || (((v->getType().isa<VectorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))) || (((v->getType().isa<TensorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))))) {
        return emitOpError("operand #") << index << " must be integer-like";
      }
      ++index;
    }
    for (Value *v : getODSOperands(1)) {
      (void)v;
      if (!(((v->getType().isa<IntegerType>())) || ((v->getType().isa<IndexType>())) || (((v->getType().isa<VectorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))) || (((v->getType().isa<TensorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))))) {
        return emitOpError("operand #") << index << " must be integer-like";
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSResults(0)) {
      (void)v;
      if (!((true))) {
        return emitOpError("result #") << index << " must be any type";
      }
      ++index;
    }
  }
  if (this->getOperation()->getNumRegions() != 0) {
    return emitOpError("has incorrect number of regions: expected 0 but found ") << this->getOperation()->getNumRegions();
  }
  return mlir::success();
}




//===----------------------------------------------------------------------===//
// RankOp definitions
//===----------------------------------------------------------------------===//

RankOpOperandAdaptor::RankOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> RankOpOperandAdaptor::getODSOperands(unsigned index) {
return {std::next(tblgen_operands.begin(), index), std::next(tblgen_operands.begin(), index + 1)};
}

StringRef RankOp::getOperationName() {
  return "std.rank";
}

Operation::operand_range RankOp::getODSOperands(unsigned index) {
return {std::next(getOperation()->operand_begin(), index), std::next(getOperation()->operand_begin(), index + 1)};
}

Operation::result_range RankOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

void RankOp::build(Builder *builder, OperationState *result, Value *tensor) {
      auto indexType = builder->getIndexType();
      build(builder, result, indexType, tensor);
    
}

void RankOp::build(Builder *, OperationState *tblgen_state, Type resultType0, Value *tblgen_arg_0) {
  tblgen_state->addOperands(tblgen_arg_0);
  tblgen_state->addTypes(resultType0);
}

void RankOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Value *tblgen_arg_0) {
  tblgen_state->addOperands(tblgen_arg_0);
  tblgen_state->addTypes(resultTypes);
}

void RankOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  assert(operands.size() == 1u && "mismatched number of parameters");
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

ParseResult RankOp::parse(OpAsmParser *parser, OperationState *result) {
  return ::parseRankOp(parser, result);
}

void RankOp::print(OpAsmPrinter *p) {
  return ::print(p, *this);
}

LogicalResult RankOp::verify() {
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSOperands(0)) {
      (void)v;
      if (!(((v->getType().isa<TensorType>())) && ((true)))) {
        return emitOpError("operand #") << index << " must be tensor of any type values";
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSResults(0)) {
      (void)v;
      if (!((v->getType().isa<IndexType>()))) {
        return emitOpError("result #") << index << " must be index";
      }
      ++index;
    }
  }
  if (this->getOperation()->getNumRegions() != 0) {
    return emitOpError("has incorrect number of regions: expected 0 but found ") << this->getOperation()->getNumRegions();
  }
  return mlir::success();
}




//===----------------------------------------------------------------------===//
// RemFOp definitions
//===----------------------------------------------------------------------===//

RemFOpOperandAdaptor::RemFOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> RemFOpOperandAdaptor::getODSOperands(unsigned index) {
return {std::next(tblgen_operands.begin(), index), std::next(tblgen_operands.begin(), index + 1)};
}

Value *RemFOpOperandAdaptor::lhs() {
return *getODSOperands(0).begin();
}

Value *RemFOpOperandAdaptor::rhs() {
return *getODSOperands(1).begin();
}

StringRef RemFOp::getOperationName() {
  return "std.remf";
}

Operation::operand_range RemFOp::getODSOperands(unsigned index) {
return {std::next(getOperation()->operand_begin(), index), std::next(getOperation()->operand_begin(), index + 1)};
}

Value *RemFOp::lhs() {
return *getODSOperands(0).begin();
}

Value *RemFOp::rhs() {
return *getODSOperands(1).begin();
}

Operation::result_range RemFOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

void RemFOp::build(Builder *, OperationState *tblgen_state, Type resultType0, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes(resultType0);
}

void RemFOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes(resultTypes);
}

void RemFOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  assert(operands.size() == 2u && "mismatched number of parameters");
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

void RemFOp::build(Builder *, OperationState *tblgen_state, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes({lhs->getType()});

}

ParseResult RemFOp::parse(OpAsmParser *parser, OperationState *result) {
  return impl::parseBinaryOp(parser, result);
}

void RemFOp::print(OpAsmPrinter *p) {
  return printStandardBinaryOp(this->getOperation(), p);
}

LogicalResult RemFOp::verify() {
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSOperands(0)) {
      (void)v;
      if (!(((v->getType().isa<FloatType>())) || (((v->getType().isa<VectorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<FloatType>()))) || (((v->getType().isa<TensorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<FloatType>()))))) {
        return emitOpError("operand #") << index << " must be floating-point-like";
      }
      ++index;
    }
    for (Value *v : getODSOperands(1)) {
      (void)v;
      if (!(((v->getType().isa<FloatType>())) || (((v->getType().isa<VectorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<FloatType>()))) || (((v->getType().isa<TensorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<FloatType>()))))) {
        return emitOpError("operand #") << index << " must be floating-point-like";
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSResults(0)) {
      (void)v;
      if (!((true))) {
        return emitOpError("result #") << index << " must be any type";
      }
      ++index;
    }
  }
  if (this->getOperation()->getNumRegions() != 0) {
    return emitOpError("has incorrect number of regions: expected 0 but found ") << this->getOperation()->getNumRegions();
  }
  return mlir::success();
}


//===----------------------------------------------------------------------===//
// RemISOp definitions
//===----------------------------------------------------------------------===//

RemISOpOperandAdaptor::RemISOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> RemISOpOperandAdaptor::getODSOperands(unsigned index) {
return {std::next(tblgen_operands.begin(), index), std::next(tblgen_operands.begin(), index + 1)};
}

Value *RemISOpOperandAdaptor::lhs() {
return *getODSOperands(0).begin();
}

Value *RemISOpOperandAdaptor::rhs() {
return *getODSOperands(1).begin();
}

StringRef RemISOp::getOperationName() {
  return "std.remis";
}

Operation::operand_range RemISOp::getODSOperands(unsigned index) {
return {std::next(getOperation()->operand_begin(), index), std::next(getOperation()->operand_begin(), index + 1)};
}

Value *RemISOp::lhs() {
return *getODSOperands(0).begin();
}

Value *RemISOp::rhs() {
return *getODSOperands(1).begin();
}

Operation::result_range RemISOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

void RemISOp::build(Builder *, OperationState *tblgen_state, Type resultType0, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes(resultType0);
}

void RemISOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes(resultTypes);
}

void RemISOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  assert(operands.size() == 2u && "mismatched number of parameters");
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

void RemISOp::build(Builder *, OperationState *tblgen_state, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes({lhs->getType()});

}

ParseResult RemISOp::parse(OpAsmParser *parser, OperationState *result) {
  return impl::parseBinaryOp(parser, result);
}

void RemISOp::print(OpAsmPrinter *p) {
  return printStandardBinaryOp(this->getOperation(), p);
}

LogicalResult RemISOp::verify() {
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSOperands(0)) {
      (void)v;
      if (!(((v->getType().isa<IntegerType>())) || ((v->getType().isa<IndexType>())) || (((v->getType().isa<VectorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))) || (((v->getType().isa<TensorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))))) {
        return emitOpError("operand #") << index << " must be integer-like";
      }
      ++index;
    }
    for (Value *v : getODSOperands(1)) {
      (void)v;
      if (!(((v->getType().isa<IntegerType>())) || ((v->getType().isa<IndexType>())) || (((v->getType().isa<VectorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))) || (((v->getType().isa<TensorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))))) {
        return emitOpError("operand #") << index << " must be integer-like";
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSResults(0)) {
      (void)v;
      if (!((true))) {
        return emitOpError("result #") << index << " must be any type";
      }
      ++index;
    }
  }
  if (this->getOperation()->getNumRegions() != 0) {
    return emitOpError("has incorrect number of regions: expected 0 but found ") << this->getOperation()->getNumRegions();
  }
  return mlir::success();
}




//===----------------------------------------------------------------------===//
// RemIUOp definitions
//===----------------------------------------------------------------------===//

RemIUOpOperandAdaptor::RemIUOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> RemIUOpOperandAdaptor::getODSOperands(unsigned index) {
return {std::next(tblgen_operands.begin(), index), std::next(tblgen_operands.begin(), index + 1)};
}

Value *RemIUOpOperandAdaptor::lhs() {
return *getODSOperands(0).begin();
}

Value *RemIUOpOperandAdaptor::rhs() {
return *getODSOperands(1).begin();
}

StringRef RemIUOp::getOperationName() {
  return "std.remiu";
}

Operation::operand_range RemIUOp::getODSOperands(unsigned index) {
return {std::next(getOperation()->operand_begin(), index), std::next(getOperation()->operand_begin(), index + 1)};
}

Value *RemIUOp::lhs() {
return *getODSOperands(0).begin();
}

Value *RemIUOp::rhs() {
return *getODSOperands(1).begin();
}

Operation::result_range RemIUOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

void RemIUOp::build(Builder *, OperationState *tblgen_state, Type resultType0, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes(resultType0);
}

void RemIUOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes(resultTypes);
}

void RemIUOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  assert(operands.size() == 2u && "mismatched number of parameters");
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

void RemIUOp::build(Builder *, OperationState *tblgen_state, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes({lhs->getType()});

}

ParseResult RemIUOp::parse(OpAsmParser *parser, OperationState *result) {
  return impl::parseBinaryOp(parser, result);
}

void RemIUOp::print(OpAsmPrinter *p) {
  return printStandardBinaryOp(this->getOperation(), p);
}

LogicalResult RemIUOp::verify() {
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSOperands(0)) {
      (void)v;
      if (!(((v->getType().isa<IntegerType>())) || ((v->getType().isa<IndexType>())) || (((v->getType().isa<VectorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))) || (((v->getType().isa<TensorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))))) {
        return emitOpError("operand #") << index << " must be integer-like";
      }
      ++index;
    }
    for (Value *v : getODSOperands(1)) {
      (void)v;
      if (!(((v->getType().isa<IntegerType>())) || ((v->getType().isa<IndexType>())) || (((v->getType().isa<VectorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))) || (((v->getType().isa<TensorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))))) {
        return emitOpError("operand #") << index << " must be integer-like";
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSResults(0)) {
      (void)v;
      if (!((true))) {
        return emitOpError("result #") << index << " must be any type";
      }
      ++index;
    }
  }
  if (this->getOperation()->getNumRegions() != 0) {
    return emitOpError("has incorrect number of regions: expected 0 but found ") << this->getOperation()->getNumRegions();
  }
  return mlir::success();
}




//===----------------------------------------------------------------------===//
// ReturnOp definitions
//===----------------------------------------------------------------------===//

ReturnOpOperandAdaptor::ReturnOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> ReturnOpOperandAdaptor::getODSOperands(unsigned index) {
  bool isVariadic[] = {true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (tblgen_operands.size() - 0) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int offset = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;

  return {std::next(tblgen_operands.begin(), offset), std::next(tblgen_operands.begin(), offset + size)};
}

ArrayRef<Value *> ReturnOpOperandAdaptor::operands() {
return getODSOperands(0);
}

StringRef ReturnOp::getOperationName() {
  return "std.return";
}

Operation::operand_range ReturnOp::getODSOperands(unsigned index) {
  bool isVariadic[] = {true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (getOperation()->getNumOperands() - 0) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int offset = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;

  return {std::next(getOperation()->operand_begin(), offset), std::next(getOperation()->operand_begin(), offset + size)};
}

Operation::operand_range ReturnOp::operands() {
return getODSOperands(0);
}

Operation::result_range ReturnOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

void ReturnOp::build(Builder *b, OperationState *result) {
 build(b, result, llvm::None); 
}

void ReturnOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Value *> operands) {
  tblgen_state->addOperands(operands);
}

void ReturnOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 0u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

ParseResult ReturnOp::parse(OpAsmParser *parser, OperationState *result) {
  return ::parseReturnOp(parser, result);
}

void ReturnOp::print(OpAsmPrinter *p) {
  return ::print(p, *this);
}

LogicalResult ReturnOp::verify() {
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSOperands(0)) {
      (void)v;
      if (!((true))) {
        return emitOpError("operand #") << index << " must be any type";
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
  }
  if (this->getOperation()->getNumRegions() != 0) {
    return emitOpError("has incorrect number of regions: expected 0 but found ") << this->getOperation()->getNumRegions();
  }
  return ::verify(*this);
}


//===----------------------------------------------------------------------===//
// SIToFPOp definitions
//===----------------------------------------------------------------------===//

SIToFPOpOperandAdaptor::SIToFPOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> SIToFPOpOperandAdaptor::getODSOperands(unsigned index) {
return {std::next(tblgen_operands.begin(), index), std::next(tblgen_operands.begin(), index + 1)};
}

Value *SIToFPOpOperandAdaptor::in() {
return *getODSOperands(0).begin();
}

StringRef SIToFPOp::getOperationName() {
  return "std.sitofp";
}

Operation::operand_range SIToFPOp::getODSOperands(unsigned index) {
return {std::next(getOperation()->operand_begin(), index), std::next(getOperation()->operand_begin(), index + 1)};
}

Value *SIToFPOp::in() {
return *getODSOperands(0).begin();
}

Operation::result_range SIToFPOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

void SIToFPOp::build(Builder *builder, OperationState *result, Value *source, Type destType) {
       impl::buildCastOp(builder, result, source, destType);
  
}

void SIToFPOp::build(Builder *, OperationState *tblgen_state, Type resultType0, Value *in) {
  tblgen_state->addOperands(in);
  tblgen_state->addTypes(resultType0);
}

void SIToFPOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Value *in) {
  tblgen_state->addOperands(in);
  tblgen_state->addTypes(resultTypes);
}

void SIToFPOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  assert(operands.size() == 1u && "mismatched number of parameters");
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

ParseResult SIToFPOp::parse(OpAsmParser *parser, OperationState *result) {
  return impl::parseCastOp(parser, result);
}

void SIToFPOp::print(OpAsmPrinter *p) {
  return printStandardCastOp(this->getOperation(), p);
}

LogicalResult SIToFPOp::verify() {
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSOperands(0)) {
      (void)v;
      if (!((true))) {
        return emitOpError("operand #") << index << " must be any type";
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSResults(0)) {
      (void)v;
      if (!((true))) {
        return emitOpError("result #") << index << " must be any type";
      }
      ++index;
    }
  }
  if (this->getOperation()->getNumRegions() != 0) {
    return emitOpError("has incorrect number of regions: expected 0 but found ") << this->getOperation()->getNumRegions();
  }
  return ::verifyCastOp(*this);
}


//===----------------------------------------------------------------------===//
// SelectOp definitions
//===----------------------------------------------------------------------===//

SelectOpOperandAdaptor::SelectOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> SelectOpOperandAdaptor::getODSOperands(unsigned index) {
return {std::next(tblgen_operands.begin(), index), std::next(tblgen_operands.begin(), index + 1)};
}

Value *SelectOpOperandAdaptor::condition() {
return *getODSOperands(0).begin();
}

Value *SelectOpOperandAdaptor::true_value() {
return *getODSOperands(1).begin();
}

Value *SelectOpOperandAdaptor::false_value() {
return *getODSOperands(2).begin();
}

StringRef SelectOp::getOperationName() {
  return "std.select";
}

Operation::operand_range SelectOp::getODSOperands(unsigned index) {
return {std::next(getOperation()->operand_begin(), index), std::next(getOperation()->operand_begin(), index + 1)};
}

Value *SelectOp::condition() {
return *getODSOperands(0).begin();
}

Value *SelectOp::true_value() {
return *getODSOperands(1).begin();
}

Value *SelectOp::false_value() {
return *getODSOperands(2).begin();
}

Operation::result_range SelectOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

void SelectOp::build(Builder *builder, OperationState *result, Value *condition,Value *trueValue, Value *falseValue) {
      result->addOperands({condition, trueValue, falseValue});
      result->addTypes(trueValue->getType());
  
}

void SelectOp::build(Builder *, OperationState *tblgen_state, Type resultType0, Value *condition, Value *true_value, Value *false_value) {
  tblgen_state->addOperands(condition);
  tblgen_state->addOperands(true_value);
  tblgen_state->addOperands(false_value);
  tblgen_state->addTypes(resultType0);
}

void SelectOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Value *condition, Value *true_value, Value *false_value) {
  tblgen_state->addOperands(condition);
  tblgen_state->addOperands(true_value);
  tblgen_state->addOperands(false_value);
  tblgen_state->addTypes(resultTypes);
}

void SelectOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  assert(operands.size() == 3u && "mismatched number of parameters");
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

ParseResult SelectOp::parse(OpAsmParser *parser, OperationState *result) {
  return ::parseSelectOp(parser, result);
}

void SelectOp::print(OpAsmPrinter *p) {
  return ::print(p, *this);
}

LogicalResult SelectOp::verify() {
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSOperands(0)) {
      (void)v;
      if (!(((v->getType().isInteger(1))) || (((v->getType().isa<VectorType>())) && ((v->getType().cast<ShapedType>().getElementType().isInteger(1)))) || (((v->getType().isa<TensorType>())) && ((v->getType().cast<ShapedType>().getElementType().isInteger(1)))))) {
        return emitOpError("operand #") << index << " must be bool-like";
      }
      ++index;
    }
    for (Value *v : getODSOperands(1)) {
      (void)v;
      if (!((true))) {
        return emitOpError("operand #") << index << " must be any type";
      }
      ++index;
    }
    for (Value *v : getODSOperands(2)) {
      (void)v;
      if (!((true))) {
        return emitOpError("operand #") << index << " must be any type";
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSResults(0)) {
      (void)v;
      if (!((true))) {
        return emitOpError("result #") << index << " must be any type";
      }
      ++index;
    }
  }
  if (this->getOperation()->getNumRegions() != 0) {
    return emitOpError("has incorrect number of regions: expected 0 but found ") << this->getOperation()->getNumRegions();
  }
  return ::verify(*this);
}




//===----------------------------------------------------------------------===//
// ShlISOp definitions
//===----------------------------------------------------------------------===//

ShlISOpOperandAdaptor::ShlISOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> ShlISOpOperandAdaptor::getODSOperands(unsigned index) {
return {std::next(tblgen_operands.begin(), index), std::next(tblgen_operands.begin(), index + 1)};
}

Value *ShlISOpOperandAdaptor::lhs() {
return *getODSOperands(0).begin();
}

Value *ShlISOpOperandAdaptor::rhs() {
return *getODSOperands(1).begin();
}

StringRef ShlISOp::getOperationName() {
  return "std.shlis";
}

Operation::operand_range ShlISOp::getODSOperands(unsigned index) {
return {std::next(getOperation()->operand_begin(), index), std::next(getOperation()->operand_begin(), index + 1)};
}

Value *ShlISOp::lhs() {
return *getODSOperands(0).begin();
}

Value *ShlISOp::rhs() {
return *getODSOperands(1).begin();
}

Operation::result_range ShlISOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

void ShlISOp::build(Builder *, OperationState *tblgen_state, Type resultType0, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes(resultType0);
}

void ShlISOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes(resultTypes);
}

void ShlISOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  assert(operands.size() == 2u && "mismatched number of parameters");
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

void ShlISOp::build(Builder *, OperationState *tblgen_state, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes({lhs->getType()});

}

ParseResult ShlISOp::parse(OpAsmParser *parser, OperationState *result) {
  return impl::parseBinaryOp(parser, result);
}

void ShlISOp::print(OpAsmPrinter *p) {
  return printStandardBinaryOp(this->getOperation(), p);
}

LogicalResult ShlISOp::verify() {
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSOperands(0)) {
      (void)v;
      if (!(((v->getType().isa<IntegerType>())) || ((v->getType().isa<IndexType>())) || (((v->getType().isa<VectorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))) || (((v->getType().isa<TensorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))))) {
        return emitOpError("operand #") << index << " must be integer-like";
      }
      ++index;
    }
    for (Value *v : getODSOperands(1)) {
      (void)v;
      if (!(((v->getType().isa<IntegerType>())) || ((v->getType().isa<IndexType>())) || (((v->getType().isa<VectorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))) || (((v->getType().isa<TensorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))))) {
        return emitOpError("operand #") << index << " must be integer-like";
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSResults(0)) {
      (void)v;
      if (!((true))) {
        return emitOpError("result #") << index << " must be any type";
      }
      ++index;
    }
  }
  if (this->getOperation()->getNumRegions() != 0) {
    return emitOpError("has incorrect number of regions: expected 0 but found ") << this->getOperation()->getNumRegions();
  }
  return mlir::success();
}


//===----------------------------------------------------------------------===//
// StoreOp definitions
//===----------------------------------------------------------------------===//

StoreOpOperandAdaptor::StoreOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> StoreOpOperandAdaptor::getODSOperands(unsigned index) {
  bool isVariadic[] = {false, false, true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (tblgen_operands.size() - 2) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int offset = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;

  return {std::next(tblgen_operands.begin(), offset), std::next(tblgen_operands.begin(), offset + size)};
}

Value *StoreOpOperandAdaptor::value() {
return *getODSOperands(0).begin();
}

Value *StoreOpOperandAdaptor::memref() {
return *getODSOperands(1).begin();
}

ArrayRef<Value *> StoreOpOperandAdaptor::indices() {
return getODSOperands(2);
}

StringRef StoreOp::getOperationName() {
  return "std.store";
}

Operation::operand_range StoreOp::getODSOperands(unsigned index) {
  bool isVariadic[] = {false, false, true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (getOperation()->getNumOperands() - 2) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int offset = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;

  return {std::next(getOperation()->operand_begin(), offset), std::next(getOperation()->operand_begin(), offset + size)};
}

Value *StoreOp::value() {
return *getODSOperands(0).begin();
}

Value *StoreOp::memref() {
return *getODSOperands(1).begin();
}

Operation::operand_range StoreOp::indices() {
return getODSOperands(2);
}

Operation::result_range StoreOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

void StoreOp::build(Builder *, OperationState *result, Value *valueToStore, Value *memref) {
      result->addOperands(valueToStore);
      result->addOperands(memref);
  
}

void StoreOp::build(Builder *, OperationState *tblgen_state, Value *value, Value *memref, ArrayRef<Value *> indices) {
  tblgen_state->addOperands(value);
  tblgen_state->addOperands(memref);
  tblgen_state->addOperands(indices);
}

void StoreOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 0u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  assert(operands.size() >= 2u && "mismatched number of parameters");
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

ParseResult StoreOp::parse(OpAsmParser *parser, OperationState *result) {
  return ::parseStoreOp(parser, result);
}

void StoreOp::print(OpAsmPrinter *p) {
  return ::print(p, *this);
}

LogicalResult StoreOp::verify() {
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSOperands(0)) {
      (void)v;
      if (!((true))) {
        return emitOpError("operand #") << index << " must be any type";
      }
      ++index;
    }
    for (Value *v : getODSOperands(1)) {
      (void)v;
      if (!(((v->getType().isa<MemRefType>())) && ((true)))) {
        return emitOpError("operand #") << index << " must be memref of any type values";
      }
      ++index;
    }
    for (Value *v : getODSOperands(2)) {
      (void)v;
      if (!((v->getType().isa<IndexType>()))) {
        return emitOpError("operand #") << index << " must be index";
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
  }
  if (this->getOperation()->getNumRegions() != 0) {
    return emitOpError("has incorrect number of regions: expected 0 but found ") << this->getOperation()->getNumRegions();
  }
  return ::verify(*this);
}




//===----------------------------------------------------------------------===//
// SubFOp definitions
//===----------------------------------------------------------------------===//

SubFOpOperandAdaptor::SubFOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> SubFOpOperandAdaptor::getODSOperands(unsigned index) {
return {std::next(tblgen_operands.begin(), index), std::next(tblgen_operands.begin(), index + 1)};
}

Value *SubFOpOperandAdaptor::lhs() {
return *getODSOperands(0).begin();
}

Value *SubFOpOperandAdaptor::rhs() {
return *getODSOperands(1).begin();
}

StringRef SubFOp::getOperationName() {
  return "std.subf";
}

Operation::operand_range SubFOp::getODSOperands(unsigned index) {
return {std::next(getOperation()->operand_begin(), index), std::next(getOperation()->operand_begin(), index + 1)};
}

Value *SubFOp::lhs() {
return *getODSOperands(0).begin();
}

Value *SubFOp::rhs() {
return *getODSOperands(1).begin();
}

Operation::result_range SubFOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

void SubFOp::build(Builder *, OperationState *tblgen_state, Type resultType0, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes(resultType0);
}

void SubFOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes(resultTypes);
}

void SubFOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  assert(operands.size() == 2u && "mismatched number of parameters");
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

void SubFOp::build(Builder *, OperationState *tblgen_state, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes({lhs->getType()});

}

ParseResult SubFOp::parse(OpAsmParser *parser, OperationState *result) {
  return impl::parseBinaryOp(parser, result);
}

void SubFOp::print(OpAsmPrinter *p) {
  return printStandardBinaryOp(this->getOperation(), p);
}

LogicalResult SubFOp::verify() {
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSOperands(0)) {
      (void)v;
      if (!(((v->getType().isa<FloatType>())) || (((v->getType().isa<VectorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<FloatType>()))) || (((v->getType().isa<TensorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<FloatType>()))))) {
        return emitOpError("operand #") << index << " must be floating-point-like";
      }
      ++index;
    }
    for (Value *v : getODSOperands(1)) {
      (void)v;
      if (!(((v->getType().isa<FloatType>())) || (((v->getType().isa<VectorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<FloatType>()))) || (((v->getType().isa<TensorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<FloatType>()))))) {
        return emitOpError("operand #") << index << " must be floating-point-like";
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSResults(0)) {
      (void)v;
      if (!((true))) {
        return emitOpError("result #") << index << " must be any type";
      }
      ++index;
    }
  }
  if (this->getOperation()->getNumRegions() != 0) {
    return emitOpError("has incorrect number of regions: expected 0 but found ") << this->getOperation()->getNumRegions();
  }
  return mlir::success();
}




//===----------------------------------------------------------------------===//
// SubIOp definitions
//===----------------------------------------------------------------------===//

SubIOpOperandAdaptor::SubIOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> SubIOpOperandAdaptor::getODSOperands(unsigned index) {
return {std::next(tblgen_operands.begin(), index), std::next(tblgen_operands.begin(), index + 1)};
}

Value *SubIOpOperandAdaptor::lhs() {
return *getODSOperands(0).begin();
}

Value *SubIOpOperandAdaptor::rhs() {
return *getODSOperands(1).begin();
}

StringRef SubIOp::getOperationName() {
  return "std.subi";
}

Operation::operand_range SubIOp::getODSOperands(unsigned index) {
return {std::next(getOperation()->operand_begin(), index), std::next(getOperation()->operand_begin(), index + 1)};
}

Value *SubIOp::lhs() {
return *getODSOperands(0).begin();
}

Value *SubIOp::rhs() {
return *getODSOperands(1).begin();
}

Operation::result_range SubIOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

void SubIOp::build(Builder *, OperationState *tblgen_state, Type resultType0, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes(resultType0);
}

void SubIOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes(resultTypes);
}

void SubIOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  assert(operands.size() == 2u && "mismatched number of parameters");
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

void SubIOp::build(Builder *, OperationState *tblgen_state, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes({lhs->getType()});

}

ParseResult SubIOp::parse(OpAsmParser *parser, OperationState *result) {
  return impl::parseBinaryOp(parser, result);
}

void SubIOp::print(OpAsmPrinter *p) {
  return printStandardBinaryOp(this->getOperation(), p);
}

LogicalResult SubIOp::verify() {
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSOperands(0)) {
      (void)v;
      if (!(((v->getType().isa<IntegerType>())) || ((v->getType().isa<IndexType>())) || (((v->getType().isa<VectorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))) || (((v->getType().isa<TensorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))))) {
        return emitOpError("operand #") << index << " must be integer-like";
      }
      ++index;
    }
    for (Value *v : getODSOperands(1)) {
      (void)v;
      if (!(((v->getType().isa<IntegerType>())) || ((v->getType().isa<IndexType>())) || (((v->getType().isa<VectorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))) || (((v->getType().isa<TensorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))))) {
        return emitOpError("operand #") << index << " must be integer-like";
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSResults(0)) {
      (void)v;
      if (!((true))) {
        return emitOpError("result #") << index << " must be any type";
      }
      ++index;
    }
  }
  if (this->getOperation()->getNumRegions() != 0) {
    return emitOpError("has incorrect number of regions: expected 0 but found ") << this->getOperation()->getNumRegions();
  }
  return mlir::success();
}




//===----------------------------------------------------------------------===//
// TensorCastOp definitions
//===----------------------------------------------------------------------===//

TensorCastOpOperandAdaptor::TensorCastOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> TensorCastOpOperandAdaptor::getODSOperands(unsigned index) {
return {std::next(tblgen_operands.begin(), index), std::next(tblgen_operands.begin(), index + 1)};
}

StringRef TensorCastOp::getOperationName() {
  return "std.tensor_cast";
}

Operation::operand_range TensorCastOp::getODSOperands(unsigned index) {
return {std::next(getOperation()->operand_begin(), index), std::next(getOperation()->operand_begin(), index + 1)};
}

Operation::result_range TensorCastOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

void TensorCastOp::build(Builder *builder, OperationState *result, Value *source, Type destType) {
       impl::buildCastOp(builder, result, source, destType);
  
}

void TensorCastOp::build(Builder *, OperationState *tblgen_state, Type resultType0, Value *tblgen_arg_0) {
  tblgen_state->addOperands(tblgen_arg_0);
  tblgen_state->addTypes(resultType0);
}

void TensorCastOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Value *tblgen_arg_0) {
  tblgen_state->addOperands(tblgen_arg_0);
  tblgen_state->addTypes(resultTypes);
}

void TensorCastOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  assert(operands.size() == 1u && "mismatched number of parameters");
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

ParseResult TensorCastOp::parse(OpAsmParser *parser, OperationState *result) {
  return impl::parseCastOp(parser, result);
}

void TensorCastOp::print(OpAsmPrinter *p) {
  return printStandardCastOp(this->getOperation(), p);
}

LogicalResult TensorCastOp::verify() {
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSOperands(0)) {
      (void)v;
      if (!(((v->getType().isa<TensorType>())) && ((true)))) {
        return emitOpError("operand #") << index << " must be tensor of any type values";
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSResults(0)) {
      (void)v;
      if (!(((v->getType().isa<TensorType>())) && ((true)))) {
        return emitOpError("result #") << index << " must be tensor of any type values";
      }
      ++index;
    }
  }
  if (this->getOperation()->getNumRegions() != 0) {
    return emitOpError("has incorrect number of regions: expected 0 but found ") << this->getOperation()->getNumRegions();
  }
  return ::verifyCastOp(*this);
}




//===----------------------------------------------------------------------===//
// TensorLoadOp definitions
//===----------------------------------------------------------------------===//

TensorLoadOpOperandAdaptor::TensorLoadOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> TensorLoadOpOperandAdaptor::getODSOperands(unsigned index) {
return {std::next(tblgen_operands.begin(), index), std::next(tblgen_operands.begin(), index + 1)};
}

StringRef TensorLoadOp::getOperationName() {
  return "std.tensor_load";
}

Operation::operand_range TensorLoadOp::getODSOperands(unsigned index) {
return {std::next(getOperation()->operand_begin(), index), std::next(getOperation()->operand_begin(), index + 1)};
}

Operation::result_range TensorLoadOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

void TensorLoadOp::build(Builder *builder, OperationState *result, Value *memref) {
      auto memrefType = memref->getType().cast<MemRefType>();
      auto resultType = builder->getTensorType(memrefType.getShape(),
          memrefType.getElementType());
      result->addOperands(memref);
      result->addTypes(resultType);
  
}

void TensorLoadOp::build(Builder *, OperationState *tblgen_state, Type resultType0, Value *tblgen_arg_0) {
  tblgen_state->addOperands(tblgen_arg_0);
  tblgen_state->addTypes(resultType0);
}

void TensorLoadOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Value *tblgen_arg_0) {
  tblgen_state->addOperands(tblgen_arg_0);
  tblgen_state->addTypes(resultTypes);
}

void TensorLoadOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  assert(operands.size() == 1u && "mismatched number of parameters");
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

ParseResult TensorLoadOp::parse(OpAsmParser *parser, OperationState *result) {
  return ::parseTensorLoadOp(parser, result);
}

void TensorLoadOp::print(OpAsmPrinter *p) {
  return ::print(p, *this);
}

LogicalResult TensorLoadOp::verify() {
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSOperands(0)) {
      (void)v;
      if (!(((v->getType().isa<MemRefType>())) && ((true)))) {
        return emitOpError("operand #") << index << " must be memref of any type values";
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSResults(0)) {
      (void)v;
      if (!(((v->getType().isa<TensorType>())) && ((true)))) {
        return emitOpError("result #") << index << " must be tensor of any type values";
      }
      ++index;
    }
  }
  if (this->getOperation()->getNumRegions() != 0) {
    return emitOpError("has incorrect number of regions: expected 0 but found ") << this->getOperation()->getNumRegions();
  }
  return mlir::success();
}


//===----------------------------------------------------------------------===//
// TensorStoreOp definitions
//===----------------------------------------------------------------------===//

TensorStoreOpOperandAdaptor::TensorStoreOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> TensorStoreOpOperandAdaptor::getODSOperands(unsigned index) {
return {std::next(tblgen_operands.begin(), index), std::next(tblgen_operands.begin(), index + 1)};
}

Value *TensorStoreOpOperandAdaptor::tensor() {
return *getODSOperands(0).begin();
}

Value *TensorStoreOpOperandAdaptor::memref() {
return *getODSOperands(1).begin();
}

StringRef TensorStoreOp::getOperationName() {
  return "std.tensor_store";
}

Operation::operand_range TensorStoreOp::getODSOperands(unsigned index) {
return {std::next(getOperation()->operand_begin(), index), std::next(getOperation()->operand_begin(), index + 1)};
}

Value *TensorStoreOp::tensor() {
return *getODSOperands(0).begin();
}

Value *TensorStoreOp::memref() {
return *getODSOperands(1).begin();
}

Operation::result_range TensorStoreOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

void TensorStoreOp::build(Builder *, OperationState *tblgen_state, Value *tensor, Value *memref) {
  tblgen_state->addOperands(tensor);
  tblgen_state->addOperands(memref);
}

void TensorStoreOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 0u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  assert(operands.size() == 2u && "mismatched number of parameters");
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

ParseResult TensorStoreOp::parse(OpAsmParser *parser, OperationState *result) {
  return ::parseTensorStoreOp(parser, result);
}

void TensorStoreOp::print(OpAsmPrinter *p) {
  return ::print(p, *this);
}

LogicalResult TensorStoreOp::verify() {
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSOperands(0)) {
      (void)v;
      if (!(((v->getType().isa<TensorType>())) && ((true)))) {
        return emitOpError("operand #") << index << " must be tensor of any type values";
      }
      ++index;
    }
    for (Value *v : getODSOperands(1)) {
      (void)v;
      if (!(((v->getType().isa<MemRefType>())) && ((true)))) {
        return emitOpError("operand #") << index << " must be memref of any type values";
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
  }
  if (this->getOperation()->getNumRegions() != 0) {
    return emitOpError("has incorrect number of regions: expected 0 but found ") << this->getOperation()->getNumRegions();
  }
  return mlir::success();
}


//===----------------------------------------------------------------------===//
// XOrOp definitions
//===----------------------------------------------------------------------===//

XOrOpOperandAdaptor::XOrOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> XOrOpOperandAdaptor::getODSOperands(unsigned index) {
return {std::next(tblgen_operands.begin(), index), std::next(tblgen_operands.begin(), index + 1)};
}

Value *XOrOpOperandAdaptor::lhs() {
return *getODSOperands(0).begin();
}

Value *XOrOpOperandAdaptor::rhs() {
return *getODSOperands(1).begin();
}

StringRef XOrOp::getOperationName() {
  return "std.xor";
}

Operation::operand_range XOrOp::getODSOperands(unsigned index) {
return {std::next(getOperation()->operand_begin(), index), std::next(getOperation()->operand_begin(), index + 1)};
}

Value *XOrOp::lhs() {
return *getODSOperands(0).begin();
}

Value *XOrOp::rhs() {
return *getODSOperands(1).begin();
}

Operation::result_range XOrOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

void XOrOp::build(Builder *, OperationState *tblgen_state, Type resultType0, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes(resultType0);
}

void XOrOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes(resultTypes);
}

void XOrOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  assert(operands.size() == 2u && "mismatched number of parameters");
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

void XOrOp::build(Builder *, OperationState *tblgen_state, Value *lhs, Value *rhs) {
  tblgen_state->addOperands(lhs);
  tblgen_state->addOperands(rhs);
  tblgen_state->addTypes({lhs->getType()});

}

ParseResult XOrOp::parse(OpAsmParser *parser, OperationState *result) {
  return impl::parseBinaryOp(parser, result);
}

void XOrOp::print(OpAsmPrinter *p) {
  return printStandardBinaryOp(this->getOperation(), p);
}

LogicalResult XOrOp::verify() {
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSOperands(0)) {
      (void)v;
      if (!(((v->getType().isa<IntegerType>())) || ((v->getType().isa<IndexType>())) || (((v->getType().isa<VectorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))) || (((v->getType().isa<TensorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))))) {
        return emitOpError("operand #") << index << " must be integer-like";
      }
      ++index;
    }
    for (Value *v : getODSOperands(1)) {
      (void)v;
      if (!(((v->getType().isa<IntegerType>())) || ((v->getType().isa<IndexType>())) || (((v->getType().isa<VectorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))) || (((v->getType().isa<TensorType>())) && ((v->getType().cast<ShapedType>().getElementType().isa<IntegerType>()))))) {
        return emitOpError("operand #") << index << " must be integer-like";
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSResults(0)) {
      (void)v;
      if (!((true))) {
        return emitOpError("result #") << index << " must be any type";
      }
      ++index;
    }
  }
  if (this->getOperation()->getNumRegions() != 0) {
    return emitOpError("has incorrect number of regions: expected 0 but found ") << this->getOperation()->getNumRegions();
  }
  return mlir::success();
}




#endif  // GET_OP_CLASSES

