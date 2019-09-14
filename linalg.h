/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Op Declarations                                                            *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_OP_CLASSES
#undef GET_OP_CLASSES

class BufferAllocOp;
class BufferDeallocOp;
class BufferSizeOp;
class DimOp;
class LoadOp;
class RangeOp;
class SliceOp;
class StoreOp;
class SubViewOp;
class TransposeOp;
class ViewOp;
class YieldOp;

//===----------------------------------------------------------------------===//
// linalg::BufferAllocOp declarations
//===----------------------------------------------------------------------===//

class BufferAllocOpOperandAdaptor {
public:
  BufferAllocOpOperandAdaptor(ArrayRef<Value *> values);
  ArrayRef<Value *> getODSOperands(unsigned index);
  ArrayRef<Value *> size();

private:
  ArrayRef<Value *> tblgen_operands;
};
class BufferAllocOp : public Op<BufferAllocOp, OpTrait::OneResult, OpTrait::VariadicOperands> {
public:
  using Op::Op;
  using OperandAdaptor = BufferAllocOpOperandAdaptor;
  static StringRef getOperationName();
  Operation::operand_range getODSOperands(unsigned index);
  Operation::operand_range size();
  Operation::result_range getODSResults(unsigned index);
  Optional< APInt > alignment();
  static void build(Builder *b, OperationState *result, BufferType bufferType);
  static void build(Builder *b, OperationState *result, BufferType bufferType, unsigned alignment);
  static void build(Builder *b, OperationState *result, BufferType bufferType, Value *size, unsigned alignment);
  static void build(Builder *b, OperationState *result, BufferType bufferType, Value *size);
  static void build(Builder *, OperationState *tblgen_state, Type resultType0, ArrayRef<Value *> size, /*optional*/IntegerAttr alignment);
  static void build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> size, /*optional*/IntegerAttr alignment);
  static void build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes);
  static ParseResult parse(OpAsmParser *parser, OperationState *result);
  void print(OpAsmPrinter *p);
  LogicalResult verify();

    static StringRef getAlignmentAttrName() { return "alignment"; }
    BufferType getBufferType() { return getType().cast<BufferType>(); }
    Type getElementType() { return getBufferType().getElementType(); }
  
};

//===----------------------------------------------------------------------===//
// linalg::BufferDeallocOp declarations
//===----------------------------------------------------------------------===//

class BufferDeallocOpOperandAdaptor {
public:
  BufferDeallocOpOperandAdaptor(ArrayRef<Value *> values);
  ArrayRef<Value *> getODSOperands(unsigned index);
  Value *buffer();

private:
  ArrayRef<Value *> tblgen_operands;
};
class BufferDeallocOp : public Op<BufferDeallocOp, OpTrait::ZeroResult, OpTrait::OneOperand> {
public:
  using Op::Op;
  using OperandAdaptor = BufferDeallocOpOperandAdaptor;
  static StringRef getOperationName();
  Operation::operand_range getODSOperands(unsigned index);
  Value *buffer();
  Operation::result_range getODSResults(unsigned index);
  static void build(Builder *, OperationState *tblgen_state, Value *buffer);
  static void build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes);
  static ParseResult parse(OpAsmParser *parser, OperationState *result);
  void print(OpAsmPrinter *p);
  LogicalResult verify();

    BufferType getBufferType() {
      return buffer()->getType().cast<BufferType>();
    }
  
};

//===----------------------------------------------------------------------===//
// linalg::BufferSizeOp declarations
//===----------------------------------------------------------------------===//

class BufferSizeOpOperandAdaptor {
public:
  BufferSizeOpOperandAdaptor(ArrayRef<Value *> values);
  ArrayRef<Value *> getODSOperands(unsigned index);
  Value *buffer();

private:
  ArrayRef<Value *> tblgen_operands;
};
class BufferSizeOp : public Op<BufferSizeOp, OpTrait::OneResult, OpTrait::HasNoSideEffect, OpTrait::OneOperand> {
public:
  using Op::Op;
  using OperandAdaptor = BufferSizeOpOperandAdaptor;
  static StringRef getOperationName();
  Operation::operand_range getODSOperands(unsigned index);
  Value *buffer();
  Operation::result_range getODSResults(unsigned index);
  static void build(Builder *, OperationState *tblgen_state, Type resultType0, Value *buffer);
  static void build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Value *buffer);
  static void build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes);
  static ParseResult parse(OpAsmParser *parser, OperationState *result);
  void print(OpAsmPrinter *p);
  LogicalResult verify();
};

//===----------------------------------------------------------------------===//
// linalg::DimOp declarations
//===----------------------------------------------------------------------===//

class DimOpOperandAdaptor {
public:
  DimOpOperandAdaptor(ArrayRef<Value *> values);
  ArrayRef<Value *> getODSOperands(unsigned index);
  Value *view();

private:
  ArrayRef<Value *> tblgen_operands;
};
class DimOp : public Op<DimOp, OpTrait::OneResult, OpTrait::HasNoSideEffect, OpTrait::OneOperand> {
public:
  using Op::Op;
  using OperandAdaptor = DimOpOperandAdaptor;
  static StringRef getOperationName();
  Operation::operand_range getODSOperands(unsigned index);
  Value *view();
  Operation::result_range getODSResults(unsigned index);
  APInt index();
  static void build(Builder *builder, OperationState *result, Value *view, unsigned index);
  static void build(Builder *, OperationState *tblgen_state, Type resultType0, Value *view, IntegerAttr index);
  static void build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Value *view, IntegerAttr index);
  static void build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes);
  static ParseResult parse(OpAsmParser *parser, OperationState *result);
  void print(OpAsmPrinter *p);
  LogicalResult verify();
  static void getCanonicalizationPatterns(OwningRewritePatternList &results, MLIRContext *context);

    unsigned getIndex() {
      return getAttrOfType<IntegerAttr>("index").getValue().getZExtValue();
    }
    ViewType getViewType() { return getOperand()->getType().cast<ViewType>(); }
  
};

//===----------------------------------------------------------------------===//
// linalg::LoadOp declarations
//===----------------------------------------------------------------------===//

class LoadOpOperandAdaptor {
public:
  LoadOpOperandAdaptor(ArrayRef<Value *> values);
  ArrayRef<Value *> getODSOperands(unsigned index);
  Value *view();
  ArrayRef<Value *> indices();

private:
  ArrayRef<Value *> tblgen_operands;
};
class LoadOp : public Op<LoadOp, OpTrait::OneResult, OpTrait::AtLeastNOperands<1>::Impl> {
public:
  using Op::Op;
  using OperandAdaptor = LoadOpOperandAdaptor;
  static StringRef getOperationName();
  Operation::operand_range getODSOperands(unsigned index);
  Value *view();
  Operation::operand_range indices();
  Operation::result_range getODSResults(unsigned index);
  Value *value();
  static void build(Builder *builder, OperationState *result, Value *view, ArrayRef<Value*> indices);
  static void build(Builder *, OperationState *tblgen_state, Type value, Value *view, ArrayRef<Value *> indices);
  static void build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Value *view, ArrayRef<Value *> indices);
  static void build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes);
  static ParseResult parse(OpAsmParser *parser, OperationState *result);
  void print(OpAsmPrinter *p);
  LogicalResult verify();

    unsigned getRank() { return getViewType().getRank(); }
    ViewType getViewType() { return view()->getType().cast<ViewType>(); }
  
};

//===----------------------------------------------------------------------===//
// linalg::RangeOp declarations
//===----------------------------------------------------------------------===//

class RangeOpOperandAdaptor {
public:
  RangeOpOperandAdaptor(ArrayRef<Value *> values);
  ArrayRef<Value *> getODSOperands(unsigned index);
  Value *min();
  Value *max();
  Value *step();

private:
  ArrayRef<Value *> tblgen_operands;
};
class RangeOp : public Op<RangeOp, OpTrait::OneResult, OpTrait::HasNoSideEffect, OpTrait::NOperands<3>::Impl> {
public:
  using Op::Op;
  using OperandAdaptor = RangeOpOperandAdaptor;
  static StringRef getOperationName();
  Operation::operand_range getODSOperands(unsigned index);
  Value *min();
  Value *max();
  Value *step();
  Operation::result_range getODSResults(unsigned index);
  static void build(Builder *builder, OperationState *result, Value *min, Value *max, Value *step);
  static void build(Builder *, OperationState *tblgen_state, Type resultType0, Value *min, Value *max, Value *step);
  static void build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Value *min, Value *max, Value *step);
  static void build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes);
  static ParseResult parse(OpAsmParser *parser, OperationState *result);
  void print(OpAsmPrinter *p);
  LogicalResult verify();
};

//===----------------------------------------------------------------------===//
// linalg::SliceOp declarations
//===----------------------------------------------------------------------===//

class SliceOpOperandAdaptor {
public:
  SliceOpOperandAdaptor(ArrayRef<Value *> values);
  ArrayRef<Value *> getODSOperands(unsigned index);
  Value *view();
  ArrayRef<Value *> indexings();

private:
  ArrayRef<Value *> tblgen_operands;
};
class SliceOp : public Op<SliceOp, OpTrait::OneResult, OpTrait::HasNoSideEffect, OpTrait::AtLeastNOperands<1>::Impl> {
public:
  using Op::Op;
  using OperandAdaptor = SliceOpOperandAdaptor;
  static StringRef getOperationName();
  Operation::operand_range getODSOperands(unsigned index);
  Value *view();
  Operation::operand_range indexings();
  Operation::result_range getODSResults(unsigned index);
  static void build(Builder *b, OperationState *result, Value *base, ArrayRef<Value *> indexings);
  static void build(Builder *, OperationState *tblgen_state, Type resultType0, Value *view, ArrayRef<Value *> indexings);
  static void build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Value *view, ArrayRef<Value *> indexings);
  static void build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes);
  static ParseResult parse(OpAsmParser *parser, OperationState *result);
  void print(OpAsmPrinter *p);
  LogicalResult verify();

    enum { FirstIndexingOperand = 1 };
    unsigned getRank() { return getViewType().getRank(); }
    Type getElementType() { return getViewType().getElementType(); }
    ViewType getViewType() { return getType().cast<ViewType>(); }
    unsigned getBaseViewRank() { return getBaseViewType().getRank(); }
    ViewType getBaseViewType() { return view()->getType().cast<ViewType>(); }

    // Get the underlying indexing at a given rank.
    Value *indexing(unsigned rank) { return *(indexings().begin() + rank); }

    // Get the subset of indexings that are of RangeType.
    SmallVector<Value *, 8> getRanges() {
      llvm::SmallVector<Value *, 8> res;
      for (auto *operand : indexings())
        if (!operand->getType().isa<IndexType>())
          res.push_back(operand);
      return res;
    }
  
};

//===----------------------------------------------------------------------===//
// linalg::StoreOp declarations
//===----------------------------------------------------------------------===//

class StoreOpOperandAdaptor {
public:
  StoreOpOperandAdaptor(ArrayRef<Value *> values);
  ArrayRef<Value *> getODSOperands(unsigned index);
  Value *value();
  Value *view();
  ArrayRef<Value *> indices();

private:
  ArrayRef<Value *> tblgen_operands;
};
class StoreOp : public Op<StoreOp, OpTrait::ZeroResult, OpTrait::AtLeastNOperands<2>::Impl> {
public:
  using Op::Op;
  using OperandAdaptor = StoreOpOperandAdaptor;
  static StringRef getOperationName();
  Operation::operand_range getODSOperands(unsigned index);
  Value *value();
  Value *view();
  Operation::operand_range indices();
  Operation::result_range getODSResults(unsigned index);
  static void build(Builder *, OperationState *tblgen_state, Value *value, Value *view, ArrayRef<Value *> indices);
  static void build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes);
  static ParseResult parse(OpAsmParser *parser, OperationState *result);
  void print(OpAsmPrinter *p);
  LogicalResult verify();

    unsigned getRank() { return getViewType().getRank(); }
    ViewType getViewType() { return view()->getType().cast<ViewType>(); }
  
};

//===----------------------------------------------------------------------===//
// linalg::SubViewOp declarations
//===----------------------------------------------------------------------===//

class SubViewOpOperandAdaptor {
public:
  SubViewOpOperandAdaptor(ArrayRef<Value *> values);
  ArrayRef<Value *> getODSOperands(unsigned index);
  Value *view();
  ArrayRef<Value *> ranges();

private:
  ArrayRef<Value *> tblgen_operands;
};
class SubViewOp : public Op<SubViewOp, OpTrait::OneResult, OpTrait::HasNoSideEffect, OpTrait::AtLeastNOperands<1>::Impl> {
public:
  using Op::Op;
  using OperandAdaptor = SubViewOpOperandAdaptor;
  static StringRef getOperationName();
  Operation::operand_range getODSOperands(unsigned index);
  Value *view();
  Operation::operand_range ranges();
  Operation::result_range getODSResults(unsigned index);
  static void build(Builder *builder, OperationState *result, Value *view, ArrayRef<Value *> ranges);
  static void build(Builder *, OperationState *tblgen_state, Type resultType0, Value *view, ArrayRef<Value *> ranges);
  static void build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Value *view, ArrayRef<Value *> ranges);
  static void build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes);
  static ParseResult parse(OpAsmParser *parser, OperationState *result);
  void print(OpAsmPrinter *p);
  LogicalResult verify();

    Value *getView() { return getOperand(0); }
    ViewType getViewType() { return getView()->getType().cast<ViewType>(); }

    struct Range { Value *min; Value *max; Value *step; };

    Range getRange(unsigned i) {
      return Range{
        getOperand(1 + 3*i), getOperand(1 + 3*i + 1), getOperand(1 + 3*i + 2)};
    }

    SmallVector<Range, 8> getRanges() {
      SmallVector<Range, 8> res;
      unsigned rank = getViewType().getRank();
      res.reserve(rank);
      for (unsigned i = 0; i < rank; ++i)
        res.push_back(getRange(i));
      return res;
    }

    // This requires `SubViewOp` to be declared, in the future it should be
    // folded into the builders.
    static void build(Builder *builder, OperationState *result, Value *view,
        ArrayRef<SubViewOp::Range> ranges) {
      result->addOperands(view);
      for (auto r : ranges)
        result->addOperands({r.min, r.max, r.step});
      result->types.push_back(view->getType());
    }
  
};

//===----------------------------------------------------------------------===//
// linalg::TransposeOp declarations
//===----------------------------------------------------------------------===//

class TransposeOpOperandAdaptor {
public:
  TransposeOpOperandAdaptor(ArrayRef<Value *> values);
  ArrayRef<Value *> getODSOperands(unsigned index);
  Value *view();

private:
  ArrayRef<Value *> tblgen_operands;
};
class TransposeOp : public Op<TransposeOp, OpTrait::OneResult, OpTrait::HasNoSideEffect, OpTrait::OneOperand> {
public:
  using Op::Op;
  using OperandAdaptor = TransposeOpOperandAdaptor;
  static StringRef getOperationName();
  Operation::operand_range getODSOperands(unsigned index);
  Value *view();
  Operation::result_range getODSResults(unsigned index);
  AffineMap permutation();
  static void build(Builder *b, OperationState *result, Value *view, AffineMapAttr permutation, ArrayRef<NamedAttribute> attrs = {});
  static void build(Builder *, OperationState *tblgen_state, Type resultType0, Value *view, AffineMapAttr permutation);
  static void build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Value *view, AffineMapAttr permutation);
  static void build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes);
  static ParseResult parse(OpAsmParser *parser, OperationState *result);
  void print(OpAsmPrinter *p);
  LogicalResult verify();

    static StringRef getPermutationAttrName() { return "permutation"; }
    ViewType getViewType() { return view()->getType().cast<ViewType>(); }
  
};

//===----------------------------------------------------------------------===//
// linalg::ViewOp declarations
//===----------------------------------------------------------------------===//

class ViewOpOperandAdaptor {
public:
  ViewOpOperandAdaptor(ArrayRef<Value *> values);
  ArrayRef<Value *> getODSOperands(unsigned index);
  Value *buffer();
  ArrayRef<Value *> ranges();

private:
  ArrayRef<Value *> tblgen_operands;
};
class ViewOp : public Op<ViewOp, OpTrait::OneResult, OpTrait::HasNoSideEffect, OpTrait::AtLeastNOperands<1>::Impl> {
public:
  using Op::Op;
  using OperandAdaptor = ViewOpOperandAdaptor;
  static StringRef getOperationName();
  Operation::operand_range getODSOperands(unsigned index);
  Value *buffer();
  Operation::operand_range ranges();
  Operation::result_range getODSResults(unsigned index);
  static void build(Builder *b, OperationState *result, Value *buffer, ArrayRef<Value *> ranges, Type resultType = Type(), ArrayRef<NamedAttribute> attrs = {});
  static void build(Builder *, OperationState *tblgen_state, Type resultType0, Value *buffer, ArrayRef<Value *> ranges);
  static void build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, Value *buffer, ArrayRef<Value *> ranges);
  static void build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes);
  static ParseResult parse(OpAsmParser *parser, OperationState *result);
  void print(OpAsmPrinter *p);
  LogicalResult verify();

    enum { FirstIndexingOperand = 1 };
    unsigned getRank() { return getViewType().getRank(); }
    Type getElementType() { return getViewType().getElementType(); }
    ViewType getViewType() { return getType().cast<ViewType>(); }
    /// Get the underlying indexing at a given rank.
    Value *getRange(unsigned rank) {
      assert(rank < getRank() && "rank overflow");
      return *(ranges().begin() + rank);
    }
  
};

//===----------------------------------------------------------------------===//
// linalg::YieldOp declarations
//===----------------------------------------------------------------------===//

class YieldOpOperandAdaptor {
public:
  YieldOpOperandAdaptor(ArrayRef<Value *> values);
  ArrayRef<Value *> getODSOperands(unsigned index);
  ArrayRef<Value *> values();

private:
  ArrayRef<Value *> tblgen_operands;
};
class YieldOp : public Op<YieldOp, OpTrait::ZeroResult, OpTrait::IsTerminator, OpTrait::VariadicOperands> {
public:
  using Op::Op;
  using OperandAdaptor = YieldOpOperandAdaptor;
  static StringRef getOperationName();
  Operation::operand_range getODSOperands(unsigned index);
  Operation::operand_range values();
  Operation::result_range getODSResults(unsigned index);
  static void build(Builder *, OperationState *tblgen_state, ArrayRef<Value *> values);
  static void build(Builder *, OperationState *tblgen_state, ArrayRef<Type> resultTypes, ArrayRef<Value *> operands, ArrayRef<NamedAttribute> attributes);
  static ParseResult parse(OpAsmParser *parser, OperationState *result);
  void print(OpAsmPrinter *p);
  LogicalResult verify();
};

#endif  // GET_OP_CLASSES

