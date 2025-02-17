// required for old g++ to compile PRId64 macros, see
// https://github.com/pytorch/pytorch/issues/3571
// for context
#define __STDC_FORMAT_MACROS

#include <ATen/QuantizedCPUType.h>

// @generated by aten/src/ATen/gen.py

#include <c10/core/TensorImpl.h>
#include <ATen/CPUGenerator.h>
#include <c10/core/Allocator.h>
#include <ATen/DeviceGuard.h>
#include <ATen/NativeFunctions.h>
#ifdef BUILD_NAMEDTENSOR
#include <ATen/NamedTensorUtils.h>
#endif
#include <ATen/Utils.h>
#include <ATen/WrapDimUtils.h>
#include <ATen/Dispatch.h>
#include <c10/util/Half.h>
#include <c10/core/TensorImpl.h>
#include <c10/core/UndefinedTensorImpl.h>
#include <c10/util/Optional.h>
#include <ATen/core/ATenDispatch.h>

#include <cstddef>
#include <functional>
#include <memory>
#include <utility>

#include <ATen/Config.h>



namespace at {

/* example
Tensor * QuantizedCPUType::add(Tensor & a, Tensor & b) {
  std::cout << "add Tensor with backend QuantizedCPU\n";
  return &a;
}
*/

Tensor QuantizedCPUType::as_strided(const Tensor & self, IntArrayRef size, IntArrayRef stride, c10::optional<int64_t> storage_offset) {
#ifdef BUILD_NAMEDTENSOR

#endif
    // DeviceGuard omitted
    return at::native::as_strided_qtensorimpl(self, size, stride, storage_offset);
}
Tensor QuantizedCPUType::_empty_affine_quantized(IntArrayRef size, const TensorOptions & options, double scale, int64_t zero_point, c10::optional<MemoryFormat> memory_format) {
#ifdef BUILD_NAMEDTENSOR

#endif
    const DeviceGuard device_guard(options.device());
    return at::native::empty_affine_quantized_cpu(size, options, scale, zero_point, memory_format);
}
Tensor QuantizedCPUType::quantized_max_pool2d(const Tensor & self, IntArrayRef kernel_size, IntArrayRef stride, IntArrayRef padding, IntArrayRef dilation) {
#ifdef BUILD_NAMEDTENSOR
    if (self.has_names()) {
        AT_ERROR("quantized_max_pool2d: no named inference rule implemented.");
    }
#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::quantized_max_pool2d(self, kernel_size, stride, padding, dilation);
}
Tensor QuantizedCPUType::relu(const Tensor & self) {
#ifdef BUILD_NAMEDTENSOR
    if (self.has_names()) {
        AT_ERROR("relu: no named inference rule implemented.");
    }
#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::quantized_relu(self);
}
Tensor & QuantizedCPUType::relu_(Tensor & self) {
#ifdef BUILD_NAMEDTENSOR

#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::quantized_relu_(self);
}
Tensor QuantizedCPUType::clone(const Tensor & self) {
#ifdef BUILD_NAMEDTENSOR

#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::quantized_clone(self);
}
Tensor QuantizedCPUType::dequantize(const Tensor & self) {
#ifdef BUILD_NAMEDTENSOR
    if (self.has_names()) {
        AT_ERROR("dequantize: no named inference rule implemented.");
    }
#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::dequantize_quant(self);
}
double QuantizedCPUType::q_scale(const Tensor & self) {
#ifdef BUILD_NAMEDTENSOR
    if (self.has_names()) {
        AT_ERROR("q_scale: no named inference rule implemented.");
    }
#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::q_scale_quant(self);
}
int64_t QuantizedCPUType::q_zero_point(const Tensor & self) {
#ifdef BUILD_NAMEDTENSOR
    if (self.has_names()) {
        AT_ERROR("q_zero_point: no named inference rule implemented.");
    }
#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::q_zero_point_quant(self);
}
Tensor QuantizedCPUType::int_repr(const Tensor & self) {
#ifdef BUILD_NAMEDTENSOR
    if (self.has_names()) {
        AT_ERROR("int_repr: no named inference rule implemented.");
    }
#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::int_repr_quant(self);
}
QScheme QuantizedCPUType::qscheme(const Tensor & self) {
#ifdef BUILD_NAMEDTENSOR
    if (self.has_names()) {
        AT_ERROR("qscheme: no named inference rule implemented.");
    }
#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::qscheme_quant(self);
}
Tensor & QuantizedCPUType::set_(Tensor & self, Storage source, int64_t storage_offset, IntArrayRef size, IntArrayRef stride) {
#ifdef BUILD_NAMEDTENSOR
    if (self.has_names()) {
        AT_ERROR("set_: no named inference rule implemented.");
    }
#endif
    // DeviceGuard omitted
    return at::native::set_storage(self, source, storage_offset, size, stride);
}
Tensor & QuantizedCPUType::set_quantizer_(Tensor & self, ConstQuantizerPtr quantizer) {
#ifdef BUILD_NAMEDTENSOR
    if (self.has_names()) {
        AT_ERROR("set_quantizer_: no named inference rule implemented.");
    }
#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::set_quantizer_(self, quantizer);
}
Tensor QuantizedCPUType::view(const Tensor & self, IntArrayRef size) {
#ifdef BUILD_NAMEDTENSOR
    if (self.has_names()) {
        AT_ERROR("view: no named inference rule implemented.");
    }
#endif
    // DeviceGuard omitted
    return at::native::view(self, size);
}
Tensor QuantizedCPUType::min(const Tensor & self) {
#ifdef BUILD_NAMEDTENSOR
    if (self.has_names()) {
        AT_ERROR("min: no named inference rule implemented.");
    }
#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::min_quant(self);
}
Tensor QuantizedCPUType::max(const Tensor & self) {
#ifdef BUILD_NAMEDTENSOR
    if (self.has_names()) {
        AT_ERROR("max: no named inference rule implemented.");
    }
#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::max_quant(self);
}
std::tuple<Tensor,Tensor> QuantizedCPUType::sort(const Tensor & self, int64_t dim, bool descending) {
#ifdef BUILD_NAMEDTENSOR
    if (self.has_names()) {
        AT_ERROR("sort: no named inference rule implemented.");
    }
#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::sort_quant(self, dim, descending);
}
bool QuantizedCPUType::equal(const Tensor & self, const Tensor & other) {
#ifdef BUILD_NAMEDTENSOR
    if (self.has_names() || other.has_names()) {
        AT_ERROR("equal: no named inference rule implemented.");
    }
#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::quantized_equal(self, other);
}
Tensor & QuantizedCPUType::adaptive_avg_pool2d_out(Tensor & out, const Tensor & self, IntArrayRef output_size) {
#ifdef BUILD_NAMEDTENSOR
    if (out.has_names() || self.has_names()) {
        AT_ERROR("adaptive_avg_pool2d_out: no named inference rule implemented.");
    }
#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::quantized_adaptive_avg_pool2d_out(out, self, output_size);
}
Tensor QuantizedCPUType::_adaptive_avg_pool2d(const Tensor & self, IntArrayRef output_size) {
#ifdef BUILD_NAMEDTENSOR
    if (self.has_names()) {
        AT_ERROR("_adaptive_avg_pool2d: no named inference rule implemented.");
    }
#endif
    const OptionalDeviceGuard device_guard(device_of(self));
    return at::native::quantized_adaptive_avg_pool2d(self, output_size);
}

static auto& registerer = globalATenDispatch()
  .registerOp<Tensor (const Tensor &, IntArrayRef, IntArrayRef, c10::optional<int64_t>)>(Backend::QuantizedCPU, "aten::as_strided(Tensor(a) self, int[] size, int[] stride, int? storage_offset=None) -> Tensor(a)", &QuantizedCPUType::as_strided)
  .registerOp<Tensor (IntArrayRef, const TensorOptions &, double, int64_t, c10::optional<MemoryFormat>)>(Backend::QuantizedCPU, "aten::_empty_affine_quantized(int[] size, *, ScalarType? dtype=None, Layout? layout=None, Device? device=None, bool? pin_memory=None, float scale=1, int zero_point=0, MemoryFormat? memory_format=contiguous_format) -> Tensor", &QuantizedCPUType::_empty_affine_quantized)
  .registerOp<Tensor (const Tensor &, IntArrayRef, IntArrayRef, IntArrayRef, IntArrayRef)>(Backend::QuantizedCPU, "aten::quantized_max_pool2d(Tensor self, int[2] kernel_size, int[2] stride=[], int[2] padding=0, int[2] dilation=1) -> Tensor", &QuantizedCPUType::quantized_max_pool2d)
  .registerOp<Tensor (const Tensor &)>(Backend::QuantizedCPU, "aten::relu(Tensor self) -> Tensor", &QuantizedCPUType::relu)
  .registerOp<Tensor & (Tensor &)>(Backend::QuantizedCPU, "aten::relu_(Tensor(a!) self) -> Tensor(a!)", &QuantizedCPUType::relu_)
  .registerOp<Tensor (const Tensor &)>(Backend::QuantizedCPU, "aten::clone(Tensor self) -> Tensor", &QuantizedCPUType::clone)
  .registerOp<Tensor (const Tensor &)>(Backend::QuantizedCPU, "aten::dequantize(Tensor self) -> Tensor", &QuantizedCPUType::dequantize)
  .registerOp<double (const Tensor &)>(Backend::QuantizedCPU, "aten::q_scale(Tensor self) -> float", &QuantizedCPUType::q_scale)
  .registerOp<int64_t (const Tensor &)>(Backend::QuantizedCPU, "aten::q_zero_point(Tensor self) -> int", &QuantizedCPUType::q_zero_point)
  .registerOp<Tensor (const Tensor &)>(Backend::QuantizedCPU, "aten::int_repr(Tensor self) -> Tensor", &QuantizedCPUType::int_repr)
  .registerOp<QScheme (const Tensor &)>(Backend::QuantizedCPU, "aten::qscheme(Tensor self) -> QScheme", &QuantizedCPUType::qscheme)
  .registerOp<Tensor & (Tensor &, Storage, int64_t, IntArrayRef, IntArrayRef)>(Backend::QuantizedCPU, "aten::set_.source_Storage_storage_offset(Tensor(a!) self, Storage source, int storage_offset, int[] size, int[] stride=[]) -> Tensor(a!)", &QuantizedCPUType::set_)
  .registerOp<Tensor & (Tensor &, ConstQuantizerPtr)>(Backend::QuantizedCPU, "aten::set_quantizer_(Tensor(a!) self, ConstQuantizerPtr quantizer) -> Tensor(a!)", &QuantizedCPUType::set_quantizer_)
  .registerOp<Tensor (const Tensor &, IntArrayRef)>(Backend::QuantizedCPU, "aten::view(Tensor(a) self, int[] size) -> Tensor(a)", &QuantizedCPUType::view)
  .registerOp<Tensor (const Tensor &)>(Backend::QuantizedCPU, "aten::min(Tensor self) -> Tensor", &QuantizedCPUType::min)
  .registerOp<Tensor (const Tensor &)>(Backend::QuantizedCPU, "aten::max(Tensor self) -> Tensor", &QuantizedCPUType::max)
  .registerOp<std::tuple<Tensor,Tensor> (const Tensor &, int64_t, bool)>(Backend::QuantizedCPU, "aten::sort(Tensor self, int dim=-1, bool descending=False) -> (Tensor values, Tensor indices)", &QuantizedCPUType::sort)
  .registerOp<bool (const Tensor &, const Tensor &)>(Backend::QuantizedCPU, "aten::equal(Tensor self, Tensor other) -> bool", &QuantizedCPUType::equal)
  .registerOp<Tensor & (Tensor &, const Tensor &, IntArrayRef)>(Backend::QuantizedCPU, "aten::adaptive_avg_pool2d.out(Tensor self, int[2] output_size, *, Tensor(a!) out) -> Tensor(a!)", &QuantizedCPUType::adaptive_avg_pool2d_out)
  .registerOp<Tensor (const Tensor &, IntArrayRef)>(Backend::QuantizedCPU, "aten::_adaptive_avg_pool2d(Tensor self, int[2] output_size) -> Tensor", &QuantizedCPUType::_adaptive_avg_pool2d);
}
