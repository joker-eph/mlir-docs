<!-- Autogenerated by mlir-tblgen; don't manually edit -->
# Operation definition
## std.addf (AddFOp)
floating point addition operation

### Description:


### Operands:
1. `lhs`: floating-point-like
1. `rhs`: floating-point-like

### Attributes:

### Results:
1. &laquo;unnamed&raquo;: any type

## std.addi (AddIOp)
integer addition operation

### Description:


### Operands:
1. `lhs`: integer-like
1. `rhs`: integer-like

### Attributes:

### Results:
1. &laquo;unnamed&raquo;: any type

## std.alloc (AllocOp)
memory allocation operation

### Description:

The "alloc" operation allocates a region of memory, as specified by its
memref type. For example:

  %0 = alloc() : memref<8x64xf32, (d0, d1) -> (d0, d1), 1>

The optional list of dimension operands are bound to the dynamic dimensions
specified in its memref type. In the example below, the ssa value '%d' is
bound to the second dimension of the memref (which is dynamic).

  %0 = alloc(%d) : memref<8x?xf32, (d0, d1) -> (d0, d1), 1>

The optional list of symbol operands are bound to the symbols of the
memrefs affine map. In the example below, the ssa value '%s' is bound to
the symbol 's0' in the affine map specified in the allocs memref type.

  %0 = alloc()[%s] : memref<8x64xf32, (d0, d1)[s0] -> ((d0 + s0), d1), 1>

This operation returns a single ssa value of memref type, which can be used
by subsequent load and store operations.

### Operands:
1. `value`: index

### Attributes:

### Results:
1. &laquo;unnamed&raquo;: memref of any type values

## std.and (AndOp)
integer binary and

### Description:


### Operands:
1. `lhs`: integer-like
1. `rhs`: integer-like

### Attributes:

### Results:
1. &laquo;unnamed&raquo;: any type

## std.br (BranchOp)
branch operation

### Description:

The "br" operation represents a branch operation in a function.
The operation takes variable number of operands and produces no results.
The operand number and types for each successor must match the arguments of
the block successor. For example:

  ^bb2:
    %2 = call @someFn()
    br ^bb3(%2 : tensor<*xf32>)
  ^bb3(%3: tensor<*xf32>):

### Operands:
1. `operands`: any type

### Attributes:

### Results:

## std.call_indirect (CallIndirectOp)
indirect call operation

### Description:

The "call_indirect" operation represents an indirect call to a value of
function type.  Functions are first class types in MLIR, and may be passed
as arguments and merged together with block arguments.  The operands
and result types of the call must match the specified function type.

  %3 = call_indirect %2(%0, %1) : (f32, f32) -> f32

### Operands:
1. `callee`: function type
1. `operands`: any type

### Attributes:

### Results:
1. &laquo;unnamed&raquo;: any type

## std.call (CallOp)
call operation

### Description:

The "call" operation represents a direct call to a function.  The operands
and result types of the call must match the specified function type.  The
callee is encoded as a function attribute named "callee".

  %2 = call @my_add(%0, %1) : (f32, f32) -> f32

### Operands:
1. `operands`: any type

### Attributes:
| Attribute | MLIR Type | Description |
| :-------: | :-------: | ----------- |
| `callee` | `SymbolRefAttr` | symbol reference attribute attribute |

### Results:
1. &laquo;unnamed&raquo;: any type

## std.cmpf (CmpFOp)
floating-point comparison operation

### Description:

The "cmpf" operation compares its two operands according to the float
comparison rules and the predicate specified by the respective attribute.
The predicate defines the type of comparison: (un)orderedness, (in)equality
and signed less/greater than (or equal to) as well as predicates that are
always true or false.  The operands must have the same type, and this type
must be a float type, or a vector or tensor thereof.  The result is an i1,
or a vector/tensor thereof having the same shape as the inputs. Unlike cmpi,
the operands are always treated as signed. The u prefix indicates
*unordered* comparison, not unsigned comparison, so "une" means unordered or
not equal. For the sake of readability by humans, custom assembly form for
the operation uses a string-typed attribute for the predicate.  The value of
this attribute corresponds to lower-cased name of the predicate constant,
e.g., "one" means "ordered not equal".  The string representation of the
attribute is merely a syntactic sugar and is converted to an integer
attribute by the parser.

  %r1 = cmpf "oeq" %0, %1 : f32
  %r2 = cmpf "ult" %0, %1 : tensor<42x42xf64>
  %r3 = "std.cmpf"(%0, %1) {predicate: 0} : (f8, f8) -> i1

### Operands:
1. `lhs`: floating-point-like
1. `rhs`: floating-point-like

### Attributes:

### Results:
1. &laquo;unnamed&raquo;: bool-like

## std.cmpi (CmpIOp)
integer comparison operation

### Description:

The "cmpi" operation compares its two operands according to the integer
comparison rules and the predicate specified by the respective attribute.
The predicate defines the type of comparison: (in)equality, (un)signed
less/greater than (or equal to).  The operands must have the same type, and
this type must be an integer type, a vector or a tensor thereof.  The result
is an i1, or a vector/tensor thereof having the same shape as the inputs.
Since integers are signless, the predicate also explicitly indicates
whether to interpret the operands as signed or unsigned integers for
less/greater than comparisons.  For the sake of readability by humans,
custom assembly form for the operation uses a string-typed attribute for
the predicate.  The value of this attribute corresponds to lower-cased name
of the predicate constant, e.g., "slt" means "signed less than".  The string
representation of the attribute is merely a syntactic sugar and is converted
to an integer attribute by the parser.

  %r1 = cmpi "eq" %0, %1 : i32
  %r2 = cmpi "slt" %0, %1 : tensor<42x42xi64>
  %r3 = "std.cmpi"(%0, %1){predicate: 0} : (i8, i8) -> i1

### Operands:
1. `lhs`: integer-like
1. `rhs`: integer-like

### Attributes:

### Results:
1. &laquo;unnamed&raquo;: bool-like

## std.cond_br (CondBranchOp)
conditional branch operation

### Description:

The "cond_br" operation represents a conditional branch operation in a
function. The operation takes variable number of operands and produces
no results. The operand number and types for each successor must match the
arguments of the block successor. For example:

  ^bb0:
     %0 = extract_element %arg0[] : tensor<i1>
     cond_br %0, ^bb1, ^bb2
  ^bb1:
     ...
  ^bb2:
     ...

### Operands:
1. `condition`: 1-bit integer
1. `branchOperands`: any type

### Attributes:

### Results:

## std.constant (ConstantOp)
constant

### Description:


### Operands:

### Attributes:
| Attribute | MLIR Type | Description |
| :-------: | :-------: | ----------- |
| `value` | `Attribute` | any attribute attribute |

### Results:
1. &laquo;unnamed&raquo;: any type

## std.dealloc (DeallocOp)
memory deallocation operation

### Description:

The "dealloc" operation frees the region of memory referenced by a memref
which was originally created by the "alloc" operation.
The "dealloc" operation should not be called on memrefs which alias an
alloc'd memref (i.e. memrefs returned by the "view" and "reshape"
operations).

  %0 = alloc() : memref<8x64xf32, (d0, d1) -> (d0, d1), 1>
  dealloc %0 : memref<8x64xf32, (d0, d1) -> (d0, d1), 1>

### Operands:
1. `memref`: memref of any type values

### Attributes:

### Results:

## std.dim (DimOp)
dimension index operation

### Description:

The "dim" operation takes a memref or tensor operand and returns an "index".
It requires a single integer attribute named "index". It returns the size
of the specified dimension. For example:

  %1 = dim %0, 2 : tensor<?x?x?xf32>

### Operands:
1. `memrefOrTensor`: any tensor or memref type

### Attributes:
| Attribute | MLIR Type | Description |
| :-------: | :-------: | ----------- |
| `index` | `IntegerAttr` | arbitrary integer attribute attribute |

### Results:
1. &laquo;unnamed&raquo;: index

## std.divf (DivFOp)
floating point division operation

### Description:


### Operands:
1. `lhs`: floating-point-like
1. `rhs`: floating-point-like

### Attributes:

### Results:
1. &laquo;unnamed&raquo;: any type

## std.divis (DivISOp)
signed integer division operation

### Description:


### Operands:
1. `lhs`: integer-like
1. `rhs`: integer-like

### Attributes:

### Results:
1. &laquo;unnamed&raquo;: any type

## std.diviu (DivIUOp)
unsigned integer division operation

### Description:


### Operands:
1. `lhs`: integer-like
1. `rhs`: integer-like

### Attributes:

### Results:
1. &laquo;unnamed&raquo;: any type

## std.extract_element (ExtractElementOp)
element extract operation

### Description:

The "extract_element" op reads a tensor or vector and returns one element
from it specified by an index list. The output of extract is a new value
with the same type as the elements of the tensor or vector. The arity of
indices matches the rank of the accessed value (i.e., if a tensor is of rank
3, then 3 indices are required for the extract).  The indices should all be
of affine_int type. For example:

  %0 = extract_element %0[%1, %2] : vector<4x4xi32>

### Operands:
1. `aggregate`: vector of any type values or tensor of any type values
1. `indices`: index

### Attributes:

### Results:
1. &laquo;unnamed&raquo;: any type

## std.index_cast (IndexCastOp)
cast between index and integer types

### Description:

Casts between integer scalars and 'index' scalars.  Index is an integer of
platform-specific bit width.  If casting to a wider integer, the value is
sign-extended.  If casting to a narrower integer, the value is truncated.

### Operands:
1. `in`: any type

### Attributes:

### Results:
1. &laquo;unnamed&raquo;: any type

## std.load (LoadOp)
load operation

### Description:

The "load" op reads an element from a memref specified by an index list. The
output of load is a new value with the same type as the elements of the
memref. The arity of indices is the rank of the memref (i.e., if the memref
loaded from is of rank 3, then 3 indices are required for the load following
the memref identifier). For example:

  %3 = load %0[%1, %1] : memref<4x4xi32>

### Operands:
1. `memref`: memref of any type values
1. `indices`: index

### Attributes:

### Results:
1. &laquo;unnamed&raquo;: any type

## std.memref_cast (MemRefCastOp)
memref cast operation

### Description:

The "memref_cast" operation converts a memref from one type to an equivalent
type with a compatible shape. The source and destination types are
when both are memref types with the same element type, affine mappings,
address space, and rank but where the individual dimensions may add or
remove constant dimensions from the memref type.

If the cast converts any dimensions from an unknown to a known size, then it
acts as an assertion that fails at runtime of the dynamic dimensions
disagree with resultant destination size.

Assert that the input dynamic shape matches the destination static shape.
   %2 = memref_cast %1 : memref<?x?xf32> to memref<4x4xf32>
Erase static shape information, replacing it with dynamic information.
   %3 = memref_cast %1 : memref<4xf32> to memref<?xf32>

### Operands:
1. `source`: memref of any type values

### Attributes:

### Results:
1. &laquo;unnamed&raquo;: memref of any type values

## std.mulf (MulFOp)
foating point multiplication operation

### Description:


### Operands:
1. `lhs`: floating-point-like
1. `rhs`: floating-point-like

### Attributes:

### Results:
1. &laquo;unnamed&raquo;: any type

## std.muli (MulIOp)
integer multiplication operation

### Description:


### Operands:
1. `lhs`: integer-like
1. `rhs`: integer-like

### Attributes:

### Results:
1. &laquo;unnamed&raquo;: any type

## std.or (OrOp)
integer binary or

### Description:


### Operands:
1. `lhs`: integer-like
1. `rhs`: integer-like

### Attributes:

### Results:
1. &laquo;unnamed&raquo;: any type

## std.rank (RankOp)
rank operation

### Description:

The "rank" operation takes a tensor operand and returns its rank.

  %1 = rank %0 : index

### Operands:
1. &laquo;unnamed&raquo;: tensor of any type values

### Attributes:

### Results:
1. &laquo;unnamed&raquo;: index

## std.remf (RemFOp)
floating point division remainder operation

### Description:


### Operands:
1. `lhs`: floating-point-like
1. `rhs`: floating-point-like

### Attributes:

### Results:
1. &laquo;unnamed&raquo;: any type

## std.remis (RemISOp)
signed integer division remainder operation

### Description:


### Operands:
1. `lhs`: integer-like
1. `rhs`: integer-like

### Attributes:

### Results:
1. &laquo;unnamed&raquo;: any type

## std.remiu (RemIUOp)
unsigned integer division remainder operation

### Description:


### Operands:
1. `lhs`: integer-like
1. `rhs`: integer-like

### Attributes:

### Results:
1. &laquo;unnamed&raquo;: any type

## std.return (ReturnOp)
return operation

### Description:

The "return" operation represents a return operation within a function.
The operation takes variable number of operands and produces no results.
The operand number and types must match the signature of the function
that contains the operation. For example:

  func @foo() : (i32, f8) {
  ...
  return %0, %1 : i32, f8

### Operands:
1. `operands`: any type

### Attributes:

### Results:

## std.sitofp (SIToFPOp)
cast from integer type to floating-point

### Description:

Cast from a value interpreted as signed integer to the corresponding
floating-point value. If the value cannot be exactly represented, it is
rounded using the default rounding mode. Only scalars are currently
supported.

### Operands:
1. `in`: any type

### Attributes:

### Results:
1. &laquo;unnamed&raquo;: any type

## std.select (SelectOp)
select operation

### Description:

The "select" operation chooses one value based on a binary condition
supplied as its first operand. If the value of the first operand is 1, the
second operand is chosen, otherwise the third operand is chosen. The second
and the third operand must have the same type. The operation applies
elementwise to vectors and tensors.  The shape of all arguments must be
identical. For example, the maximum operation is obtained by combining
"select" with "cmpi" as follows.

  %2 = cmpi "gt" %0, %1 : i32         // %2 is i1
  %3 = select %2, %0, %1 : i32

### Operands:
1. `condition`: bool-like
1. `true_value`: any type
1. `false_value`: any type

### Attributes:

### Results:
1. &laquo;unnamed&raquo;: any type

## std.shlis (ShlISOp)
signed integer shift left

### Description:


### Operands:
1. `lhs`: integer-like
1. `rhs`: integer-like

### Attributes:

### Results:
1. &laquo;unnamed&raquo;: any type

## std.store (StoreOp)
store operation

### Description:

The "store" op writes an element to a memref specified by an index list.
The arity of indices is the rank of the memref (i.e. if the memref being
stored to is of rank 3, then 3 indices are required for the store following
the memref identifier). The store operation does not produce a result.

In the following example, the ssa value '%v' is stored in memref '%A' at
indices [%i, %j]:
  store %v, %A[%i, %j] : memref<4x128xf32, (d0, d1) -> (d0, d1), 0>

### Operands:
1. `value`: any type
1. `memref`: memref of any type values
1. `indices`: index

### Attributes:

### Results:

## std.subf (SubFOp)
floating point subtraction operation

### Description:


### Operands:
1. `lhs`: floating-point-like
1. `rhs`: floating-point-like

### Attributes:

### Results:
1. &laquo;unnamed&raquo;: any type

## std.subi (SubIOp)
integer subtraction operation

### Description:


### Operands:
1. `lhs`: integer-like
1. `rhs`: integer-like

### Attributes:

### Results:
1. &laquo;unnamed&raquo;: any type

## std.tensor_cast (TensorCastOp)
tensor cast operation

### Description:

The "tensor_cast" operation converts a tensor from one type to an equivalent
type without changing any data elements.  The source and destination types
must both be tensor types with the same element type.  If both are ranked
then the rank should be the same and static dimensions should match.  The
operation is invalid if converting to a mismatching constant dimension.

Convert from unknown rank to rank 2 with unknown dimension sizes.
   %2 = tensor_cast %1 : tensor<*xf32> to tensor<?x?xf32>

### Operands:
1. &laquo;unnamed&raquo;: tensor of any type values

### Attributes:

### Results:
1. &laquo;unnamed&raquo;: tensor of any type values

## std.tensor_load (TensorLoadOp)
tensor load operation

### Description:

The "tensor_load" operation creates a tensor from a memref, making an
independent copy of the element data. The result value is a tensor whose
shape and element type match the memref operand.

Produce a value of tensor<4x?xf32> type.
   %12 = tensor_load %10 : memref<4x?xf32, #layout, memspace0>

### Operands:
1. &laquo;unnamed&raquo;: memref of any type values

### Attributes:

### Results:
1. &laquo;unnamed&raquo;: tensor of any type values

## std.tensor_store (TensorStoreOp)
tensor store operation

### Description:

The "tensor_store" operation stores the contents of a tensor into a memref.
The first operand is a value of tensor type, the second operand is a value
of memref type. The shapes and element types of these must match, and are
specified by the memref type.

Example:
   %9 = dim %8, 1 : tensor<4x?xf32>
   %10 = alloc(%9) : memref<4x?xf32, #layout, memspace0>
   tensor_store %8, %10 : memref<4x?xf32, #layout, memspace0>

### Operands:
1. `tensor`: tensor of any type values
1. `memref`: memref of any type values

### Attributes:

### Results:

## std.xor (XOrOp)
integer binary xor

### Description:


### Operands:
1. `lhs`: integer-like
1. `rhs`: integer-like

### Attributes:

### Results:
1. &laquo;unnamed&raquo;: any type

