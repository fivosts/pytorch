// required for old g++ to compile PRId64 macros, see
// https://github.com/pytorch/pytorch/issues/3571
// for context
#define __STDC_FORMAT_MACROS

#include <ATen/SparseCUDAType.h>

// @generated by aten/src/ATen/gen.py

#include <ATen/CUDAGenerator.h>
#include <c10/core/Allocator.h>
#include <ATen/DeviceGuard.h>
#include <ATen/NativeFunctions.h>
#include <ATen/Utils.h>
#include <ATen/WrapDimUtils.h>
#include <ATen/Dispatch.h>
#include <c10/util/Half.h>
#include <c10/core/UndefinedTensorImpl.h>
#include <c10/util/Optional.h>

#include <cstddef>
#include <functional>
#include <memory>
#include <utility>

#include <ATen/Config.h>
#include <ATen/DeviceGuard.h>
#include <ATen/cuda/ATenCUDAGeneral.h>
#include <ATen/cuda/CUDADevice.h>
#include <ATen/cuda/CUDAContext.h>

namespace at {

Tensor SparseCUDAType::add(const Tensor & self, const Tensor & other, Scalar alpha) {
#ifdef BUILD_NAMEDTENSOR

#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::add(self, other, alpha);
}
Tensor & SparseCUDAType::add_(Tensor & self, const Tensor & other, Scalar alpha) {
#ifdef BUILD_NAMEDTENSOR

#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::add_(self, other, alpha);
}
Tensor & SparseCUDAType::add_out(Tensor & out, const Tensor & self, const Tensor & other, Scalar alpha) {
#ifdef BUILD_NAMEDTENSOR

#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::add_out(out, self, other, alpha);
}
Tensor SparseCUDAType::empty(IntArrayRef size, const TensorOptions & options, c10::optional<MemoryFormat> memory_format) {
#ifdef BUILD_NAMEDTENSOR

#endif
    const DeviceGuard device_guard(options.device());
    return at::native::empty_sparse(size, options, memory_format);
}
Tensor & SparseCUDAType::log1p_(Tensor & self) {
#ifdef BUILD_NAMEDTENSOR

#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::log1p_sparse_(self);
}
Tensor & SparseCUDAType::log1p_out(Tensor & out, const Tensor & self) {
#ifdef BUILD_NAMEDTENSOR

#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::log1p_out_sparse(out, self);
}
Tensor SparseCUDAType::mm(const Tensor & self, const Tensor & mat2) {
#ifdef BUILD_NAMEDTENSOR
    if (self.has_names() || mat2.has_names()) {
        AT_ERROR("mm: no named inference rule implemented.");
    }
#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::_sparse_mm(self, mat2);
}
Tensor & SparseCUDAType::mm_out(Tensor & out, const Tensor & self, const Tensor & mat2) {
#ifdef BUILD_NAMEDTENSOR
    if (out.has_names() || self.has_names() || mat2.has_names()) {
        AT_ERROR("mm_out: no named inference rule implemented.");
    }
#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::_sparse_mm_out(out, self, mat2);
}
Tensor SparseCUDAType::mul(const Tensor & self, const Tensor & other) {
#ifdef BUILD_NAMEDTENSOR

#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::mul(self, other);
}
Tensor & SparseCUDAType::mul_(Tensor & self, const Tensor & other) {
#ifdef BUILD_NAMEDTENSOR

#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::mul_(self, other);
}
Tensor & SparseCUDAType::mul_out(Tensor & out, const Tensor & self, const Tensor & other) {
#ifdef BUILD_NAMEDTENSOR

#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::mul_out(out, self, other);
}
Tensor SparseCUDAType::narrow_copy(const Tensor & self, int64_t dim, int64_t start, int64_t length) {
#ifdef BUILD_NAMEDTENSOR
    if (self.has_names()) {
        AT_ERROR("narrow_copy: no named inference rule implemented.");
    }
#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::narrow_copy_sparse(self, dim, start, length);
}
Tensor & SparseCUDAType::_sparse_add_out(Tensor & out, const Tensor & self, const Tensor & other, Scalar alpha) {
#ifdef BUILD_NAMEDTENSOR
    if (out.has_names() || self.has_names() || other.has_names()) {
        AT_ERROR("_sparse_add_out: no named inference rule implemented.");
    }
#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::add_out_sparse_cuda(out, self, other, alpha);
}
Tensor & SparseCUDAType::_sparse_div_zerodim_out(Tensor & out, const Tensor & self, const Tensor & other) {
#ifdef BUILD_NAMEDTENSOR
    if (out.has_names() || self.has_names() || other.has_names()) {
        AT_ERROR("_sparse_div_zerodim_out: no named inference rule implemented.");
    }
#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::div_out_sparse_zerodim(out, self, other);
}
Tensor & SparseCUDAType::_sparse_div_scalar_out(Tensor & out, const Tensor & self, Scalar other) {
#ifdef BUILD_NAMEDTENSOR
    if (out.has_names() || self.has_names()) {
        AT_ERROR("_sparse_div_scalar_out: no named inference rule implemented.");
    }
#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::div_out_sparse_scalar(out, self, other);
}
Tensor & SparseCUDAType::_sparse_mul_out(Tensor & out, const Tensor & self, const Tensor & other) {
#ifdef BUILD_NAMEDTENSOR
    if (out.has_names() || self.has_names() || other.has_names()) {
        AT_ERROR("_sparse_mul_out: no named inference rule implemented.");
    }
#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::mul_out_sparse_cuda(out, self, other);
}
Tensor & SparseCUDAType::_sparse_mul_zerodim_out(Tensor & out, const Tensor & self, const Tensor & other) {
#ifdef BUILD_NAMEDTENSOR
    if (out.has_names() || self.has_names() || other.has_names()) {
        AT_ERROR("_sparse_mul_zerodim_out: no named inference rule implemented.");
    }
#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::mul_out_sparse_zerodim(out, self, other);
}
Tensor & SparseCUDAType::_sparse_mul_scalar_out(Tensor & out, const Tensor & self, Scalar other) {
#ifdef BUILD_NAMEDTENSOR
    if (out.has_names() || self.has_names()) {
        AT_ERROR("_sparse_mul_scalar_out: no named inference rule implemented.");
    }
#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::mul_out_sparse_scalar(out, self, other);
}
Tensor & SparseCUDAType::sspaddmm_out(Tensor & out, const Tensor & self, const Tensor & mat1, const Tensor & mat2, Scalar beta, Scalar alpha) {
#ifdef BUILD_NAMEDTENSOR
    if (out.has_names() || self.has_names() || mat1.has_names() || mat2.has_names()) {
        AT_ERROR("sspaddmm_out: no named inference rule implemented.");
    }
#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::_sspaddmm_out_cuda(out, self, mat1, mat2, beta, alpha);
}
Tensor SparseCUDAType::native_norm(const Tensor & self, Scalar p) {
#ifdef BUILD_NAMEDTENSOR
    if (self.has_names()) {
        AT_ERROR("native_norm: no named inference rule implemented.");
    }
#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::norm_sparse(self, p);
}
Tensor SparseCUDAType::_sparse_sum_backward(const Tensor & grad, const Tensor & self, IntArrayRef dim) {
#ifdef BUILD_NAMEDTENSOR
    if (grad.has_names() || self.has_names()) {
        AT_ERROR("_sparse_sum_backward: no named inference rule implemented.");
    }
#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::_sparse_sum_backward_cuda(grad, self, dim);
}
Tensor SparseCUDAType::clone(const Tensor & self) {
#ifdef BUILD_NAMEDTENSOR

#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::clone_sparse(self);
}
Tensor & SparseCUDAType::resize_as_(Tensor & self, const Tensor & the_template) {
#ifdef BUILD_NAMEDTENSOR
    if (self.has_names() || the_template.has_names()) {
        AT_ERROR("resize_as_: no named inference rule implemented.");
    }
#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::resize_as_sparse_(self, the_template);
}
Tensor & SparseCUDAType::pow_out(Tensor & out, const Tensor & self, Scalar exponent) {
#ifdef BUILD_NAMEDTENSOR
    if (out.has_names() || self.has_names()) {
        AT_ERROR("pow_out: no named inference rule implemented.");
    }
#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::pow_out_sparse_scalar(out, self, exponent);
}
Tensor SparseCUDAType::pow(const Tensor & self, Scalar exponent) {
#ifdef BUILD_NAMEDTENSOR
    if (self.has_names()) {
        AT_ERROR("pow: no named inference rule implemented.");
    }
#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::pow_sparse_scalar(self, exponent);
}
Tensor & SparseCUDAType::zero_(Tensor & self) {
#ifdef BUILD_NAMEDTENSOR

#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::zero_sparse_(self);
}
Tensor SparseCUDAType::_sparse_coo_tensor_with_dims(int64_t sparse_dim, int64_t dense_dim, IntArrayRef size, const TensorOptions & options) {
#ifdef BUILD_NAMEDTENSOR

#endif
    const DeviceGuard device_guard(options.device());
    return at::native::new_with_dims_sparse(sparse_dim, dense_dim, size, options);
}
Tensor SparseCUDAType::_sparse_coo_tensor_with_dims_and_tensors(int64_t sparse_dim, int64_t dense_dim, IntArrayRef size, const Tensor & indices, const Tensor & values, const TensorOptions & options) {
#ifdef BUILD_NAMEDTENSOR
    if (indices.has_names() || values.has_names()) {
        AT_ERROR("_sparse_coo_tensor_with_dims_and_tensors: no named inference rule implemented.");
    }
#endif
    const DeviceGuard device_guard(options.device());
    return at::native::new_with_dims_and_tensor_sparse(sparse_dim, dense_dim, size, indices, values, options);
}
Tensor & SparseCUDAType::sparse_resize_(Tensor & self, IntArrayRef size, int64_t sparse_dim, int64_t dense_dim) {
#ifdef BUILD_NAMEDTENSOR
    if (self.has_names()) {
        AT_ERROR("sparse_resize_: no named inference rule implemented.");
    }
#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::sparse_resize_(self, size, sparse_dim, dense_dim);
}
Tensor & SparseCUDAType::sparse_resize_and_clear_(Tensor & self, IntArrayRef size, int64_t sparse_dim, int64_t dense_dim) {
#ifdef BUILD_NAMEDTENSOR
    if (self.has_names()) {
        AT_ERROR("sparse_resize_and_clear_: no named inference rule implemented.");
    }
#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::sparse_resize_and_clear_(self, size, sparse_dim, dense_dim);
}
Tensor SparseCUDAType::to_dense(const Tensor & self) {
#ifdef BUILD_NAMEDTENSOR
    if (self.has_names()) {
        AT_ERROR("to_dense: no named inference rule implemented.");
    }
#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::sparse_to_dense(self);
}
int64_t SparseCUDAType::sparse_dim(const Tensor & self) {
#ifdef BUILD_NAMEDTENSOR
    if (self.has_names()) {
        AT_ERROR("sparse_dim: no named inference rule implemented.");
    }
#endif
    // DeviceGuard omitted
    return at::native::sparse_dim_sparse(self);
}
int64_t SparseCUDAType::_dimI(const Tensor & self) {
#ifdef BUILD_NAMEDTENSOR
    if (self.has_names()) {
        AT_ERROR("_dimI: no named inference rule implemented.");
    }
#endif
    // DeviceGuard omitted
    return at::native::sparse_dim_sparse(self);
}
int64_t SparseCUDAType::dense_dim(const Tensor & self) {
#ifdef BUILD_NAMEDTENSOR
    if (self.has_names()) {
        AT_ERROR("dense_dim: no named inference rule implemented.");
    }
#endif
    // DeviceGuard omitted
    return at::native::dense_dim_sparse(self);
}
int64_t SparseCUDAType::_dimV(const Tensor & self) {
#ifdef BUILD_NAMEDTENSOR
    if (self.has_names()) {
        AT_ERROR("_dimV: no named inference rule implemented.");
    }
#endif
    // DeviceGuard omitted
    return at::native::dense_dim_sparse(self);
}
int64_t SparseCUDAType::_nnz(const Tensor & self) {
#ifdef BUILD_NAMEDTENSOR
    if (self.has_names()) {
        AT_ERROR("_nnz: no named inference rule implemented.");
    }
#endif
    // DeviceGuard omitted
    return at::native::_nnz_sparse(self);
}
Tensor SparseCUDAType::coalesce(const Tensor & self) {
#ifdef BUILD_NAMEDTENSOR
    if (self.has_names()) {
        AT_ERROR("coalesce: no named inference rule implemented.");
    }
#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::coalesce_sparse_cuda(self);
}
bool SparseCUDAType::is_coalesced(const Tensor & self) {
#ifdef BUILD_NAMEDTENSOR

#endif
    // DeviceGuard omitted
    return at::native::is_coalesced_sparse(self);
}
Tensor SparseCUDAType::_indices(const Tensor & self) {
#ifdef BUILD_NAMEDTENSOR
    if (self.has_names()) {
        AT_ERROR("_indices: no named inference rule implemented.");
    }
#endif
    // DeviceGuard omitted
    return at::native::_indices_sparse(self);
}
Tensor SparseCUDAType::_values(const Tensor & self) {
#ifdef BUILD_NAMEDTENSOR
    if (self.has_names()) {
        AT_ERROR("_values: no named inference rule implemented.");
    }
#endif
    // DeviceGuard omitted
    return at::native::_values_sparse(self);
}
Tensor & SparseCUDAType::_coalesced_(Tensor & self, bool coalesced) {
#ifdef BUILD_NAMEDTENSOR
    if (self.has_names()) {
        AT_ERROR("_coalesced_: no named inference rule implemented.");
    }
#endif
    // DeviceGuard omitted
    return at::native::_coalesced_sparse_(self, coalesced);
}
Tensor SparseCUDAType::indices(const Tensor & self) {
#ifdef BUILD_NAMEDTENSOR
    if (self.has_names()) {
        AT_ERROR("indices: no named inference rule implemented.");
    }
#endif
    // DeviceGuard omitted
    return at::native::indices_sparse(self);
}
Tensor SparseCUDAType::values(const Tensor & self) {
#ifdef BUILD_NAMEDTENSOR
    if (self.has_names()) {
        AT_ERROR("values: no named inference rule implemented.");
    }
#endif
    // DeviceGuard omitted
    return at::native::values_sparse(self);
}
Tensor & SparseCUDAType::hspmm_out(Tensor & out, const Tensor & mat1, const Tensor & mat2) {
#ifdef BUILD_NAMEDTENSOR
    if (out.has_names() || mat1.has_names() || mat2.has_names()) {
        AT_ERROR("hspmm_out: no named inference rule implemented.");
    }
#endif
    const OptionalDeviceGuard device_guard(device_of(out));
    return at::native::hspmm_out_sparse_cuda(out, mat1, mat2);
}
Tensor SparseCUDAType::hspmm(const Tensor & mat1, const Tensor & mat2) {
#ifdef BUILD_NAMEDTENSOR
    if (mat1.has_names() || mat2.has_names()) {
        AT_ERROR("hspmm: no named inference rule implemented.");
    }
#endif
    const OptionalDeviceGuard device_guard(device_of(mat1));
    return at::native::hspmm_sparse_cuda(mat1, mat2);
}
Tensor & SparseCUDAType::copy_sparse_to_sparse_(Tensor & self, const Tensor & src, bool non_blocking) {
#ifdef BUILD_NAMEDTENSOR
    if (self.has_names() || src.has_names()) {
        AT_ERROR("copy_sparse_to_sparse_: no named inference rule implemented.");
    }
#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::copy_sparse_(self, src, non_blocking);
}

static auto& registerer = globalATenDispatch()
  .registerOp<Tensor (const Tensor &, const Tensor &, Scalar)>(Backend::SparseCUDA, "aten::add.Tensor(Tensor self, Tensor other, *, Scalar alpha=1) -> Tensor", &SparseCUDAType::add)
  .registerOp<Tensor & (Tensor &, const Tensor &, Scalar)>(Backend::SparseCUDA, "aten::add_.Tensor(Tensor(a!) self, Tensor other, *, Scalar alpha=1) -> Tensor(a!)", &SparseCUDAType::add_)
  .registerOp<Tensor & (Tensor &, const Tensor &, const Tensor &, Scalar)>(Backend::SparseCUDA, "aten::add.out(Tensor self, Tensor other, *, Scalar alpha=1, Tensor(a!) out) -> Tensor(a!)", &SparseCUDAType::add_out)
  .registerOp<Tensor (IntArrayRef, const TensorOptions &, c10::optional<MemoryFormat>)>(Backend::SparseCUDA, "aten::empty.memory_format(int[] size, *, ScalarType? dtype=None, Layout? layout=None, Device? device=None, bool? pin_memory=None, MemoryFormat? memory_format=None) -> Tensor", &SparseCUDAType::empty)
  .registerOp<Tensor & (Tensor &)>(Backend::SparseCUDA, "aten::log1p_(Tensor(a!) self) -> Tensor(a!)", &SparseCUDAType::log1p_)
  .registerOp<Tensor & (Tensor &, const Tensor &)>(Backend::SparseCUDA, "aten::log1p.out(Tensor self, *, Tensor(a!) out) -> Tensor(a!)", &SparseCUDAType::log1p_out)
  .registerOp<Tensor (const Tensor &, const Tensor &)>(Backend::SparseCUDA, "aten::mm(Tensor self, Tensor mat2) -> Tensor", &SparseCUDAType::mm)
  .registerOp<Tensor & (Tensor &, const Tensor &, const Tensor &)>(Backend::SparseCUDA, "aten::mm.out(Tensor self, Tensor mat2, *, Tensor(a!) out) -> Tensor(a!)", &SparseCUDAType::mm_out)
  .registerOp<Tensor (const Tensor &, const Tensor &)>(Backend::SparseCUDA, "aten::mul.Tensor(Tensor self, Tensor other) -> Tensor", &SparseCUDAType::mul)
  .registerOp<Tensor & (Tensor &, const Tensor &)>(Backend::SparseCUDA, "aten::mul_.Tensor(Tensor(a!) self, Tensor other) -> Tensor(a!)", &SparseCUDAType::mul_)
  .registerOp<Tensor & (Tensor &, const Tensor &, const Tensor &)>(Backend::SparseCUDA, "aten::mul.out(Tensor self, Tensor other, *, Tensor(a!) out) -> Tensor(a!)", &SparseCUDAType::mul_out)
  .registerOp<Tensor (const Tensor &, int64_t, int64_t, int64_t)>(Backend::SparseCUDA, "aten::narrow_copy(Tensor self, int dim, int start, int length) -> Tensor", &SparseCUDAType::narrow_copy)
  .registerOp<Tensor & (Tensor &, const Tensor &, const Tensor &, Scalar)>(Backend::SparseCUDA, "aten::_sparse_add.out(Tensor self, Tensor other, *, Scalar alpha=1, Tensor(a!) out) -> Tensor(a!)", &SparseCUDAType::_sparse_add_out)
  .registerOp<Tensor & (Tensor &, const Tensor &, const Tensor &)>(Backend::SparseCUDA, "aten::_sparse_div_zerodim.out(Tensor self, Tensor other, *, Tensor(a!) out) -> Tensor(a!)", &SparseCUDAType::_sparse_div_zerodim_out)
  .registerOp<Tensor & (Tensor &, const Tensor &, Scalar)>(Backend::SparseCUDA, "aten::_sparse_div_scalar.out(Tensor self, Scalar other, *, Tensor(a!) out) -> Tensor(a!)", &SparseCUDAType::_sparse_div_scalar_out)
  .registerOp<Tensor & (Tensor &, const Tensor &, const Tensor &)>(Backend::SparseCUDA, "aten::_sparse_mul.out(Tensor self, Tensor other, *, Tensor(a!) out) -> Tensor(a!)", &SparseCUDAType::_sparse_mul_out)
  .registerOp<Tensor & (Tensor &, const Tensor &, const Tensor &)>(Backend::SparseCUDA, "aten::_sparse_mul_zerodim.out(Tensor self, Tensor other, *, Tensor(a!) out) -> Tensor(a!)", &SparseCUDAType::_sparse_mul_zerodim_out)
  .registerOp<Tensor & (Tensor &, const Tensor &, Scalar)>(Backend::SparseCUDA, "aten::_sparse_mul_scalar.out(Tensor self, Scalar other, *, Tensor(a!) out) -> Tensor(a!)", &SparseCUDAType::_sparse_mul_scalar_out)
  .registerOp<Tensor & (Tensor &, const Tensor &, const Tensor &, const Tensor &, Scalar, Scalar)>(Backend::SparseCUDA, "aten::sspaddmm.out(Tensor self, Tensor mat1, Tensor mat2, *, Scalar beta=1, Scalar alpha=1, Tensor(a!) out) -> Tensor(a!)", &SparseCUDAType::sspaddmm_out)
  .registerOp<Tensor (const Tensor &, Scalar)>(Backend::SparseCUDA, "aten::native_norm(Tensor self, Scalar p=2) -> Tensor", &SparseCUDAType::native_norm)
  .registerOp<Tensor (const Tensor &, const Tensor &, IntArrayRef)>(Backend::SparseCUDA, "aten::_sparse_sum_backward(Tensor grad, Tensor self, int[] dim) -> Tensor", &SparseCUDAType::_sparse_sum_backward)
  .registerOp<Tensor (const Tensor &)>(Backend::SparseCUDA, "aten::clone(Tensor self) -> Tensor", &SparseCUDAType::clone)
  .registerOp<Tensor & (Tensor &, const Tensor &)>(Backend::SparseCUDA, "aten::resize_as_(Tensor(a!) self, Tensor the_template) -> Tensor(a!)", &SparseCUDAType::resize_as_)
  .registerOp<Tensor & (Tensor &, const Tensor &, Scalar)>(Backend::SparseCUDA, "aten::pow.Tensor_Scalar_out(Tensor self, Scalar exponent, *, Tensor(a!) out) -> Tensor(a!)", &SparseCUDAType::pow_out)
  .registerOp<Tensor (const Tensor &, Scalar)>(Backend::SparseCUDA, "aten::pow.Tensor_Scalar(Tensor self, Scalar exponent) -> Tensor", &SparseCUDAType::pow)
  .registerOp<Tensor & (Tensor &)>(Backend::SparseCUDA, "aten::zero_(Tensor(a!) self) -> Tensor(a!)", &SparseCUDAType::zero_)
  .registerOp<Tensor (int64_t, int64_t, IntArrayRef, const TensorOptions &)>(Backend::SparseCUDA, "aten::_sparse_coo_tensor_with_dims(int sparse_dim, int dense_dim, int[] size, *, ScalarType dtype, Layout layout, Device device, bool pin_memory=False) -> Tensor", &SparseCUDAType::_sparse_coo_tensor_with_dims)
  .registerOp<Tensor (int64_t, int64_t, IntArrayRef, const Tensor &, const Tensor &, const TensorOptions &)>(Backend::SparseCUDA, "aten::_sparse_coo_tensor_with_dims_and_tensors(int sparse_dim, int dense_dim, int[] size, Tensor indices, Tensor values, *, ScalarType dtype, Layout layout, Device device, bool pin_memory=False) -> Tensor", &SparseCUDAType::_sparse_coo_tensor_with_dims_and_tensors)
  .registerOp<Tensor & (Tensor &, IntArrayRef, int64_t, int64_t)>(Backend::SparseCUDA, "aten::sparse_resize_(Tensor(a!) self, int[] size, int sparse_dim, int dense_dim) -> Tensor(a!)", &SparseCUDAType::sparse_resize_)
  .registerOp<Tensor & (Tensor &, IntArrayRef, int64_t, int64_t)>(Backend::SparseCUDA, "aten::sparse_resize_and_clear_(Tensor(a!) self, int[] size, int sparse_dim, int dense_dim) -> Tensor(a!)", &SparseCUDAType::sparse_resize_and_clear_)
  .registerOp<Tensor (const Tensor &)>(Backend::SparseCUDA, "aten::to_dense(Tensor self) -> Tensor", &SparseCUDAType::to_dense)
  .registerOp<int64_t (const Tensor &)>(Backend::SparseCUDA, "aten::sparse_dim(Tensor self) -> int", &SparseCUDAType::sparse_dim)
  .registerOp<int64_t (const Tensor &)>(Backend::SparseCUDA, "aten::_dimI(Tensor self) -> int", &SparseCUDAType::_dimI)
  .registerOp<int64_t (const Tensor &)>(Backend::SparseCUDA, "aten::dense_dim(Tensor self) -> int", &SparseCUDAType::dense_dim)
  .registerOp<int64_t (const Tensor &)>(Backend::SparseCUDA, "aten::_dimV(Tensor self) -> int", &SparseCUDAType::_dimV)
  .registerOp<int64_t (const Tensor &)>(Backend::SparseCUDA, "aten::_nnz(Tensor self) -> int", &SparseCUDAType::_nnz)
  .registerOp<Tensor (const Tensor &)>(Backend::SparseCUDA, "aten::coalesce(Tensor self) -> Tensor", &SparseCUDAType::coalesce)
  .registerOp<bool (const Tensor &)>(Backend::SparseCUDA, "aten::is_coalesced(Tensor self) -> bool", &SparseCUDAType::is_coalesced)
  .registerOp<Tensor (const Tensor &)>(Backend::SparseCUDA, "aten::_indices(Tensor(a) self) -> Tensor(a)", &SparseCUDAType::_indices)
  .registerOp<Tensor (const Tensor &)>(Backend::SparseCUDA, "aten::_values(Tensor(a) self) -> Tensor(a)", &SparseCUDAType::_values)
  .registerOp<Tensor & (Tensor &, bool)>(Backend::SparseCUDA, "aten::_coalesced_(Tensor(a!) self, bool coalesced) -> Tensor(a!)", &SparseCUDAType::_coalesced_)
  .registerOp<Tensor (const Tensor &)>(Backend::SparseCUDA, "aten::indices(Tensor(a) self) -> Tensor(a)", &SparseCUDAType::indices)
  .registerOp<Tensor (const Tensor &)>(Backend::SparseCUDA, "aten::values(Tensor(a) self) -> Tensor(a)", &SparseCUDAType::values)
  .registerOp<Tensor & (Tensor &, const Tensor &, const Tensor &)>(Backend::SparseCUDA, "aten::hspmm.out(Tensor mat1, Tensor mat2, *, Tensor(a!) out) -> Tensor(a!)", &SparseCUDAType::hspmm_out)
  .registerOp<Tensor (const Tensor &, const Tensor &)>(Backend::SparseCUDA, "aten::hspmm(Tensor mat1, Tensor mat2) -> Tensor", &SparseCUDAType::hspmm)
  .registerOp<Tensor & (Tensor &, const Tensor &, bool)>(Backend::SparseCUDA, "aten::copy_sparse_to_sparse_(Tensor(a!) self, Tensor src, bool non_blocking=False) -> Tensor(a!)", &SparseCUDAType::copy_sparse_to_sparse_);

}
