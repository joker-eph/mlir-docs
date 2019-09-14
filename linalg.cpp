/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Op Definitions                                                             *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_OP_LIST
#undef GET_OP_LIST

linalg::BufferAllocOp,
linalg::BufferDeallocOp,
linalg::BufferSizeOp,
linalg::DimOp,
linalg::LoadOp,
linalg::RangeOp,
linalg::SliceOp,
linalg::StoreOp,
linalg::SubViewOp,
linalg::TransposeOp,
linalg::ViewOp,
linalg::YieldOp
#endif  // GET_OP_LIST

#ifdef GET_OP_CLASSES
#undef GET_OP_CLASSES


//===----------------------------------------------------------------------===//
// linalg::BufferAllocOp definitions
//===----------------------------------------------------------------------===//

BufferAllocOpOperandAdaptor::BufferAllocOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> BufferAllocOpOperandAdaptor::getODSOperands(unsigned index) {
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

ArrayRef<Value *> BufferAllocOpOperandAdaptor::size() {
return getODSOperands(0);
}

StringRef BufferAllocOp::getOperationName() {
  return "linalg.buffer_alloc";
}

Operation::operand_range BufferAllocOp::getODSOperands(unsigned index) {
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

Operation::operand_range BufferAllocOp::size() {
return getODSOperands(0);
}

Operation::result_range BufferAllocOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

Optional< APInt > BufferAllocOp::alignment() {
  auto attr = this->getAttr("alignment").dyn_cast_or_null<IntegerAttr>();
  return attr ? Optional< APInt >(attr.getValue()) : (llvm::None);
}

void BufferAllocOp::build(Builder *b, OperationState *result, BufferType bufferType) {
          result->addTypes(bufferType);
       
}

void BufferAllocOp::build(Builder *b, OperationState *result, BufferType bufferType, unsigned alignment) {
        build(b, result, bufferType);
        if (alignment != 0)
          result->addAttribute(BufferAllocOp::getAlignmentAttrName(),
                               b->getI64IntegerAttr(alignment));
      
}

void BufferAllocOp::build(Builder *b, OperationState *result, BufferType bufferType, Value *size, unsigned alignment) {
        if (alignment == 0)
          return build(b, result, bufferType, size);
        build(b, result, bufferType, size, b->getI64IntegerAttr(alignment));
      
}

void BufferAllocOp::build(Builder *b, OperationState *result, BufferType bufferType, Value *size) {
        result->addOperands(size);
        result->addTypes(bufferType);
      
}

void BufferAllocOp::build(Builder *, OperationState *tblgen_state, Type resultType0, ArrayRef<Value *> size, /*optional*/IntegerAttr alignment) {
  tblgen_state->addOperands(size);
  if (alignment) {
  tblgen_state->addAttribute("alignment", alignment);
  }
  tblgen_state->addTypes(resultType0);
}

void BufferAllocOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> size, /*optional*/IntegerAttr alignment) {
  tblgen_state->addOperands(size);
  if (alignment) {
  tblgen_state->addAttribute("alignment", alignment);
  }
  tblgen_state->addTypes(resultTypes);
}

void BufferAllocOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

ParseResult BufferAllocOp::parse(OpAsmParser *parser, OperationState *result) {
  return ::parseBufferAllocOp(parser, result);
}

void BufferAllocOp::print(OpAsmPrinter *p) {
  return ::print(p, *this);
}

LogicalResult BufferAllocOp::verify() {
  auto tblgen_alignment = this->getAttr("alignment");
  if (tblgen_alignment) {
    if (!(((tblgen_alignment.isa<IntegerAttr>())) && ((tblgen_alignment.cast<IntegerAttr>().getType().isInteger(64))))) return emitOpError("attribute 'alignment' failed to satisfy constraint: 64-bit integer attribute");
  }
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
      if (!((v->getType().isa<BufferType>()))) {
        return emitOpError("result #") << index << " must be buffer";
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
// linalg::BufferDeallocOp definitions
//===----------------------------------------------------------------------===//

BufferDeallocOpOperandAdaptor::BufferDeallocOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> BufferDeallocOpOperandAdaptor::getODSOperands(unsigned index) {
return {std::next(tblgen_operands.begin(), index), std::next(tblgen_operands.begin(), index + 1)};
}

Value *BufferDeallocOpOperandAdaptor::buffer() {
return *getODSOperands(0).begin();
}

StringRef BufferDeallocOp::getOperationName() {
  return "linalg.buffer_dealloc";
}

Operation::operand_range BufferDeallocOp::getODSOperands(unsigned index) {
return {std::next(getOperation()->operand_begin(), index), std::next(getOperation()->operand_begin(), index + 1)};
}

Value *BufferDeallocOp::buffer() {
return *getODSOperands(0).begin();
}

Operation::result_range BufferDeallocOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

void BufferDeallocOp::build(Builder *, OperationState *tblgen_state, Value *buffer) {
  tblgen_state->addOperands(buffer);
}

void BufferDeallocOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 0u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  assert(operands.size() == 1u && "mismatched number of parameters");
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

ParseResult BufferDeallocOp::parse(OpAsmParser *parser, OperationState *result) {
  return ::parseBufferDeallocOp(parser, result);
}

void BufferDeallocOp::print(OpAsmPrinter *p) {
  return ::print(p, *this);
}

LogicalResult BufferDeallocOp::verify() {
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSOperands(0)) {
      (void)v;
      if (!((v->getType().isa<BufferType>()))) {
        return emitOpError("operand #") << index << " must be buffer";
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
// linalg::BufferSizeOp definitions
//===----------------------------------------------------------------------===//

BufferSizeOpOperandAdaptor::BufferSizeOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> BufferSizeOpOperandAdaptor::getODSOperands(unsigned index) {
return {std::next(tblgen_operands.begin(), index), std::next(tblgen_operands.begin(), index + 1)};
}

Value *BufferSizeOpOperandAdaptor::buffer() {
return *getODSOperands(0).begin();
}

StringRef BufferSizeOp::getOperationName() {
  return "linalg.buffer_size";
}

Operation::operand_range BufferSizeOp::getODSOperands(unsigned index) {
return {std::next(getOperation()->operand_begin(), index), std::next(getOperation()->operand_begin(), index + 1)};
}

Value *BufferSizeOp::buffer() {
return *getODSOperands(0).begin();
}

Operation::result_range BufferSizeOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

void BufferSizeOp::build(Builder *, OperationState *tblgen_state, Type resultType0, Value *buffer) {
  tblgen_state->addOperands(buffer);
  tblgen_state->addTypes(resultType0);
}

void BufferSizeOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Value *buffer) {
  tblgen_state->addOperands(buffer);
  tblgen_state->addTypes(resultTypes);
}

void BufferSizeOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  assert(operands.size() == 1u && "mismatched number of parameters");
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

ParseResult BufferSizeOp::parse(OpAsmParser *parser, OperationState *result) {
  return ::parseBufferSizeOp(parser, result);
}

void BufferSizeOp::print(OpAsmPrinter *p) {
  return ::print(p, *this);
}

LogicalResult BufferSizeOp::verify() {
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSOperands(0)) {
      (void)v;
      if (!((v->getType().isa<BufferType>()))) {
        return emitOpError("operand #") << index << " must be buffer";
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
// linalg::DimOp definitions
//===----------------------------------------------------------------------===//

DimOpOperandAdaptor::DimOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> DimOpOperandAdaptor::getODSOperands(unsigned index) {
return {std::next(tblgen_operands.begin(), index), std::next(tblgen_operands.begin(), index + 1)};
}

Value *DimOpOperandAdaptor::view() {
return *getODSOperands(0).begin();
}

StringRef DimOp::getOperationName() {
  return "linalg.dim";
}

Operation::operand_range DimOp::getODSOperands(unsigned index) {
return {std::next(getOperation()->operand_begin(), index), std::next(getOperation()->operand_begin(), index + 1)};
}

Value *DimOp::view() {
return *getODSOperands(0).begin();
}

Operation::result_range DimOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

APInt DimOp::index() {
  auto attr = this->getAttr("index").cast<IntegerAttr>();
  return attr.getValue();
}

void DimOp::build(Builder *builder, OperationState *result, Value *view, unsigned index) {
      result->addOperands(view);
      result->addAttribute(
        "index", builder->getIntegerAttr(builder->getIndexType(), index));
      result->types.push_back(builder->getIndexType());
    
}

void DimOp::build(Builder *, OperationState *tblgen_state, Type resultType0, Value *view, IntegerAttr index) {
  tblgen_state->addOperands(view);
  tblgen_state->addAttribute("index", index);
  tblgen_state->addTypes(resultType0);
}

void DimOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Value *view, IntegerAttr index) {
  tblgen_state->addOperands(view);
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
      if (!((v->getType().isa<ViewType>()))) {
        return emitOpError("operand #") << index << " must be view";
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
  if (getIndex() >= getViewType().getRank())
      return emitOpError("index is out of range");
    return success();
}




//===----------------------------------------------------------------------===//
// linalg::LoadOp definitions
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

Value *LoadOpOperandAdaptor::view() {
return *getODSOperands(0).begin();
}

ArrayRef<Value *> LoadOpOperandAdaptor::indices() {
return getODSOperands(1);
}

StringRef LoadOp::getOperationName() {
  return "linalg.load";
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

Value *LoadOp::view() {
return *getODSOperands(0).begin();
}

Operation::operand_range LoadOp::indices() {
return getODSOperands(1);
}

Operation::result_range LoadOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

Value *LoadOp::value() {
return *getODSResults(0).begin();
}

void LoadOp::build(Builder *builder, OperationState *result, Value *view, ArrayRef<Value*> indices) {
      auto viewType = view->getType().cast<ViewType>();
      build(builder, result, viewType.getElementType(), view, indices);
    
}

void LoadOp::build(Builder *, OperationState *tblgen_state, Type value, Value *view, ArrayRef<Value *> indices) {
  tblgen_state->addOperands(view);
  tblgen_state->addOperands(indices);
  tblgen_state->addTypes(value);
}

void LoadOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Value *view, ArrayRef<Value *> indices) {
  tblgen_state->addOperands(view);
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
      if (!((v->getType().isa<ViewType>()))) {
        return emitOpError("operand #") << index << " must be view";
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
// linalg::RangeOp definitions
//===----------------------------------------------------------------------===//

RangeOpOperandAdaptor::RangeOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> RangeOpOperandAdaptor::getODSOperands(unsigned index) {
return {std::next(tblgen_operands.begin(), index), std::next(tblgen_operands.begin(), index + 1)};
}

Value *RangeOpOperandAdaptor::min() {
return *getODSOperands(0).begin();
}

Value *RangeOpOperandAdaptor::max() {
return *getODSOperands(1).begin();
}

Value *RangeOpOperandAdaptor::step() {
return *getODSOperands(2).begin();
}

StringRef RangeOp::getOperationName() {
  return "linalg.range";
}

Operation::operand_range RangeOp::getODSOperands(unsigned index) {
return {std::next(getOperation()->operand_begin(), index), std::next(getOperation()->operand_begin(), index + 1)};
}

Value *RangeOp::min() {
return *getODSOperands(0).begin();
}

Value *RangeOp::max() {
return *getODSOperands(1).begin();
}

Value *RangeOp::step() {
return *getODSOperands(2).begin();
}

Operation::result_range RangeOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

void RangeOp::build(Builder *builder, OperationState *result, Value *min, Value *max, Value *step) {
      auto rangeType = RangeType::get(builder->getContext());
      build(builder, result, rangeType, min, max, step);
    
}

void RangeOp::build(Builder *, OperationState *tblgen_state, Type resultType0, Value *min, Value *max, Value *step) {
  tblgen_state->addOperands(min);
  tblgen_state->addOperands(max);
  tblgen_state->addOperands(step);
  tblgen_state->addTypes(resultType0);
}

void RangeOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Value *min, Value *max, Value *step) {
  tblgen_state->addOperands(min);
  tblgen_state->addOperands(max);
  tblgen_state->addOperands(step);
  tblgen_state->addTypes(resultTypes);
}

void RangeOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  assert(operands.size() == 3u && "mismatched number of parameters");
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

ParseResult RangeOp::parse(OpAsmParser *parser, OperationState *result) {
  return ::parseRangeOp(parser, result);
}

void RangeOp::print(OpAsmPrinter *p) {
  return ::print(p, *this);
}

LogicalResult RangeOp::verify() {
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSOperands(0)) {
      (void)v;
      if (!((v->getType().isa<IndexType>()))) {
        return emitOpError("operand #") << index << " must be index";
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
    for (Value *v : getODSResults(0)) {
      (void)v;
      if (!((v->getType().isa<RangeType>()))) {
        return emitOpError("result #") << index << " must be range";
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
// linalg::SliceOp definitions
//===----------------------------------------------------------------------===//

SliceOpOperandAdaptor::SliceOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> SliceOpOperandAdaptor::getODSOperands(unsigned index) {
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

Value *SliceOpOperandAdaptor::view() {
return *getODSOperands(0).begin();
}

ArrayRef<Value *> SliceOpOperandAdaptor::indexings() {
return getODSOperands(1);
}

StringRef SliceOp::getOperationName() {
  return "linalg.slice";
}

Operation::operand_range SliceOp::getODSOperands(unsigned index) {
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

Value *SliceOp::view() {
return *getODSOperands(0).begin();
}

Operation::operand_range SliceOp::indexings() {
return getODSOperands(1);
}

Operation::result_range SliceOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}



void SliceOp::build(Builder *, OperationState *tblgen_state, Type resultType0, Value *view, ArrayRef<Value *> indexings) {
  tblgen_state->addOperands(view);
  tblgen_state->addOperands(indexings);
  tblgen_state->addTypes(resultType0);
}

void SliceOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Value *view, ArrayRef<Value *> indexings) {
  tblgen_state->addOperands(view);
  tblgen_state->addOperands(indexings);
  tblgen_state->addTypes(resultTypes);
}

void SliceOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  assert(operands.size() >= 1u && "mismatched number of parameters");
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

ParseResult SliceOp::parse(OpAsmParser *parser, OperationState *result) {
  return ::parseSliceOp(parser, result);
}

void SliceOp::print(OpAsmPrinter *p) {
  return ::print(p, *this);
}

LogicalResult SliceOp::verify() {
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSOperands(0)) {
      (void)v;
      if (!((v->getType().isa<ViewType>()))) {
        return emitOpError("operand #") << index << " must be view";
      }
      ++index;
    }
    for (Value *v : getODSOperands(1)) {
      (void)v;
      if (!(((v->getType().isa<RangeType>())) || ((v->getType().isa<IndexType>())))) {
        return emitOpError("operand #") << index << " must be range or index";
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSResults(0)) {
      (void)v;
      if (!((v->getType().isa<ViewType>()))) {
        return emitOpError("result #") << index << " must be view";
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
// linalg::StoreOp definitions
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

Value *StoreOpOperandAdaptor::view() {
return *getODSOperands(1).begin();
}

ArrayRef<Value *> StoreOpOperandAdaptor::indices() {
return getODSOperands(2);
}

StringRef StoreOp::getOperationName() {
  return "linalg.store";
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

Value *StoreOp::view() {
return *getODSOperands(1).begin();
}

Operation::operand_range StoreOp::indices() {
return getODSOperands(2);
}

Operation::result_range StoreOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

void StoreOp::build(Builder *, OperationState *tblgen_state, Value *value, Value *view, ArrayRef<Value *> indices) {
  tblgen_state->addOperands(value);
  tblgen_state->addOperands(view);
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
      if (!((v->getType().isa<ViewType>()))) {
        return emitOpError("operand #") << index << " must be view";
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
// linalg::SubViewOp definitions
//===----------------------------------------------------------------------===//

SubViewOpOperandAdaptor::SubViewOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> SubViewOpOperandAdaptor::getODSOperands(unsigned index) {
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

Value *SubViewOpOperandAdaptor::view() {
return *getODSOperands(0).begin();
}

ArrayRef<Value *> SubViewOpOperandAdaptor::ranges() {
return getODSOperands(1);
}

StringRef SubViewOp::getOperationName() {
  return "linalg.subview";
}

Operation::operand_range SubViewOp::getODSOperands(unsigned index) {
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

Value *SubViewOp::view() {
return *getODSOperands(0).begin();
}

Operation::operand_range SubViewOp::ranges() {
return getODSOperands(1);
}

Operation::result_range SubViewOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

void SubViewOp::build(Builder *builder, OperationState *result, Value *view, ArrayRef<Value *> ranges) {
      result->addOperands(view);
      result->addOperands(ranges);
      result->types.push_back(view->getType());
    
}

void SubViewOp::build(Builder *, OperationState *tblgen_state, Type resultType0, Value *view, ArrayRef<Value *> ranges) {
  tblgen_state->addOperands(view);
  tblgen_state->addOperands(ranges);
  tblgen_state->addTypes(resultType0);
}

void SubViewOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Value *view, ArrayRef<Value *> ranges) {
  tblgen_state->addOperands(view);
  tblgen_state->addOperands(ranges);
  tblgen_state->addTypes(resultTypes);
}

void SubViewOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  assert(operands.size() >= 1u && "mismatched number of parameters");
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

ParseResult SubViewOp::parse(OpAsmParser *parser, OperationState *result) {
  return ::parseSubViewOp(parser, result);
}

void SubViewOp::print(OpAsmPrinter *p) {
  return ::print(p, *this);
}

LogicalResult SubViewOp::verify() {
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSOperands(0)) {
      (void)v;
      if (!((v->getType().isa<ViewType>()))) {
        return emitOpError("operand #") << index << " must be view";
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
      if (!((v->getType().isa<ViewType>()))) {
        return emitOpError("result #") << index << " must be view";
      }
      ++index;
    }
  }
  if (this->getOperation()->getNumRegions() != 0) {
    return emitOpError("has incorrect number of regions: expected 0 but found ") << this->getOperation()->getNumRegions();
  }
  auto rank = getViewType().getRank();
    if (getNumOperands() != 3 * rank + 1)
      return emitOpError("expected a view followed by ") << (3 * rank) <<
        " indices specifying a range for each dimension";
    return success();
}


//===----------------------------------------------------------------------===//
// linalg::TransposeOp definitions
//===----------------------------------------------------------------------===//

TransposeOpOperandAdaptor::TransposeOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> TransposeOpOperandAdaptor::getODSOperands(unsigned index) {
return {std::next(tblgen_operands.begin(), index), std::next(tblgen_operands.begin(), index + 1)};
}

Value *TransposeOpOperandAdaptor::view() {
return *getODSOperands(0).begin();
}

StringRef TransposeOp::getOperationName() {
  return "linalg.transpose";
}

Operation::operand_range TransposeOp::getODSOperands(unsigned index) {
return {std::next(getOperation()->operand_begin(), index), std::next(getOperation()->operand_begin(), index + 1)};
}

Value *TransposeOp::view() {
return *getODSOperands(0).begin();
}

Operation::result_range TransposeOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

AffineMap TransposeOp::permutation() {
  auto attr = this->getAttr("permutation").cast<AffineMapAttr>();
  return attr.getValue();
}



void TransposeOp::build(Builder *, OperationState *tblgen_state, Type resultType0, Value *view, AffineMapAttr permutation) {
  tblgen_state->addOperands(view);
  tblgen_state->addAttribute("permutation", permutation);
  tblgen_state->addTypes(resultType0);
}

void TransposeOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Value *view, AffineMapAttr permutation) {
  tblgen_state->addOperands(view);
  tblgen_state->addAttribute("permutation", permutation);
  tblgen_state->addTypes(resultTypes);
}

void TransposeOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  assert(operands.size() == 1u && "mismatched number of parameters");
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

ParseResult TransposeOp::parse(OpAsmParser *parser, OperationState *result) {
  return ::parseTransposeOp(parser, result);
}

void TransposeOp::print(OpAsmPrinter *p) {
  return ::print(p, *this);
}

LogicalResult TransposeOp::verify() {
  auto tblgen_permutation = this->getAttr("permutation");
  if (!tblgen_permutation) return emitOpError("requires attribute 'permutation'");
  {
    if (!((tblgen_permutation.isa<AffineMapAttr>()))) return emitOpError("attribute 'permutation' failed to satisfy constraint: AffineMap attribute");
  }
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSOperands(0)) {
      (void)v;
      if (!((v->getType().isa<ViewType>()))) {
        return emitOpError("operand #") << index << " must be view";
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSResults(0)) {
      (void)v;
      if (!((v->getType().isa<ViewType>()))) {
        return emitOpError("result #") << index << " must be view";
      }
      ++index;
    }
  }
  if (this->getOperation()->getNumRegions() != 0) {
    return emitOpError("has incorrect number of regions: expected 0 but found ") << this->getOperation()->getNumRegions();
  }
  if (!permutation().isPermutation())
      return emitOpError("expected a permutation map");
    if (permutation().getNumDims() != getViewType().getRank())
      return emitOpError("expected a permutation map of same rank as the view");
    return success();
}


//===----------------------------------------------------------------------===//
// linalg::ViewOp definitions
//===----------------------------------------------------------------------===//

ViewOpOperandAdaptor::ViewOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> ViewOpOperandAdaptor::getODSOperands(unsigned index) {
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

Value *ViewOpOperandAdaptor::buffer() {
return *getODSOperands(0).begin();
}

ArrayRef<Value *> ViewOpOperandAdaptor::ranges() {
return getODSOperands(1);
}

StringRef ViewOp::getOperationName() {
  return "linalg.view";
}

Operation::operand_range ViewOp::getODSOperands(unsigned index) {
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

Value *ViewOp::buffer() {
return *getODSOperands(0).begin();
}

Operation::operand_range ViewOp::ranges() {
return getODSOperands(1);
}

Operation::result_range ViewOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}



void ViewOp::build(Builder *, OperationState *tblgen_state, Type resultType0, Value *buffer, ArrayRef<Value *> ranges) {
  tblgen_state->addOperands(buffer);
  tblgen_state->addOperands(ranges);
  tblgen_state->addTypes(resultType0);
}

void ViewOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Value *buffer, ArrayRef<Value *> ranges) {
  tblgen_state->addOperands(buffer);
  tblgen_state->addOperands(ranges);
  tblgen_state->addTypes(resultTypes);
}

void ViewOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  assert(operands.size() >= 1u && "mismatched number of parameters");
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

ParseResult ViewOp::parse(OpAsmParser *parser, OperationState *result) {
  return ::parseViewOp(parser, result);
}

void ViewOp::print(OpAsmPrinter *p) {
  return ::print(p, *this);
}

LogicalResult ViewOp::verify() {
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSOperands(0)) {
      (void)v;
      if (!((v->getType().isa<BufferType>()))) {
        return emitOpError("operand #") << index << " must be buffer";
      }
      ++index;
    }
    for (Value *v : getODSOperands(1)) {
      (void)v;
      if (!((v->getType().isa<RangeType>()))) {
        return emitOpError("operand #") << index << " must be range";
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    for (Value *v : getODSResults(0)) {
      (void)v;
      if (!((v->getType().isa<ViewType>()))) {
        return emitOpError("result #") << index << " must be view";
      }
      ++index;
    }
  }
  if (this->getOperation()->getNumRegions() != 0) {
    return emitOpError("has incorrect number of regions: expected 0 but found ") << this->getOperation()->getNumRegions();
  }
  if (getViewType().getRank() != llvm::size(ranges()))
      return emitOpError("the view rank must be the number of its ranges");
    return success();
}


//===----------------------------------------------------------------------===//
// linalg::YieldOp definitions
//===----------------------------------------------------------------------===//

YieldOpOperandAdaptor::YieldOpOperandAdaptor(ArrayRef<Value *> values) {
  tblgen_operands = values;
}

ArrayRef<Value *> YieldOpOperandAdaptor::getODSOperands(unsigned index) {
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

ArrayRef<Value *> YieldOpOperandAdaptor::values() {
return getODSOperands(0);
}

StringRef YieldOp::getOperationName() {
  return "linalg.yield";
}

Operation::operand_range YieldOp::getODSOperands(unsigned index) {
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

Operation::operand_range YieldOp::values() {
return getODSOperands(0);
}

Operation::result_range YieldOp::getODSResults(unsigned index) {
return {std::next(getOperation()->result_begin(), index), std::next(getOperation()->result_begin(), index + 1)};
}

void YieldOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Value *> values) {
  tblgen_state->addOperands(values);
}

void YieldOp::build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes) {
  assert(resultTypes.size() == 0u && "mismatched number of return types");
  tblgen_state->addTypes(resultTypes);
  tblgen_state->addOperands(operands);

  for (const auto& pair : attributes)
    tblgen_state->addAttribute(pair.first, pair.second);
}

ParseResult YieldOp::parse(OpAsmParser *parser, OperationState *result) {
  return ::parseYieldOp(parser, result);
}

void YieldOp::print(OpAsmPrinter *p) {
  return ::print(p, *this);
}

LogicalResult YieldOp::verify() {
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


#endif  // GET_OP_CLASSES

