#pragma once
#include <unordered_map>
#include <string>
#include <ATen/ATen.h>
#include <caffe2/core/context.h>
#include <caffe2/core/operator.h>
#include <caffe2/utils/math.h>
#include <iostream>

// a map from descriptor strings (see [DESCRIPTORS])
// to the key in the switch statement that implements them
static std::unordered_map<std::string, int> op_to_key = {
  { "_cast_Byte-non_blocking-1", 0 },
  { "_cast_Byte-1", 1 },
  { "_cast_Char-non_blocking-1", 2 },
  { "_cast_Char-1", 3 },
  { "_cast_Double-non_blocking-1", 4 },
  { "_cast_Double-1", 5 },
  { "_cast_Float-non_blocking-1", 6 },
  { "_cast_Float-1", 7 },
  { "_cast_Int-non_blocking-1", 8 },
  { "_cast_Int-1", 9 },
  { "_cast_Long-non_blocking-1", 10 },
  { "_cast_Long-1", 11 },
  { "_cast_Short-non_blocking-1", 12 },
  { "_cast_Short-1", 13 },
  { "_cast_Half-non_blocking-1", 14 },
  { "_cast_Half-1", 15 },
  { "_cudnn_ctc_loss-blank-deterministic-input_lengths-target_lengths-zero_infinity-2", 16 },
  { "_cudnn_rnn_flatten_weight-batch_first-bidirectional-hidden_size-input_size-mode-num_layers-weight_stride0-*", 17 },
  { "_cudnn_rnn-batch_first-batch_sizes-bidirectional-dropout-hidden_size-mode-num_layers-train-weight_stride0-*", 18 },
  { "_debug_has_internal_overlap-1", 19 },
  { "_fused_dropout-p-1", 20 },
  { "_masked_scale-scale-2", 21 },
  { "_reshape_from_tensor-2", 22 },
  { "_shape_as_tensor-1", 23 },
  { "dropout-p-train-1", 24 },
  { "feature_dropout-p-train-1", 25 },
  { "alpha_dropout-p-train-1", 26 },
  { "feature_alpha_dropout-p-train-1", 27 },
  { "abs-1", 28 },
  { "acos-1", 29 },
  { "avg_pool1d-ceil_mode-count_include_pad-kernel_size-padding-stride-1", 30 },
  { "avg_pool1d-ceil_mode-kernel_size-padding-stride-1", 31 },
  { "avg_pool1d-kernel_size-padding-stride-1", 32 },
  { "avg_pool1d-kernel_size-stride-1", 33 },
  { "avg_pool1d-kernel_size-1", 34 },
  { "adaptive_avg_pool1d-output_size-1", 35 },
  { "adaptive_max_pool1d-output_size-1", 36 },
  { "add-alpha-2", 37 },
  { "add-2", 38 },
  { "add-alpha-other-1", 39 },
  { "add-other-1", 40 },
  { "addmv-alpha-beta-3", 41 },
  { "addmv-beta-3", 42 },
  { "addmv-3", 43 },
  { "addr-alpha-beta-3", 44 },
  { "addr-beta-3", 45 },
  { "addr-3", 46 },
  { "affine_grid_generator-size-1", 47 },
  { "affine_grid_generator_backward-size-1", 48 },
  { "all-dim-keepdim-1", 49 },
  { "all-dim-1", 50 },
  { "allclose-atol-equal_nan-rtol-2", 51 },
  { "allclose-atol-rtol-2", 52 },
  { "allclose-rtol-2", 53 },
  { "allclose-2", 54 },
  { "any-dim-keepdim-1", 55 },
  { "any-dim-1", 56 },
  { "_dim_arange-dim-1", 57 },
  { "argmax-1", 58 },
  { "argmin-1", 59 },
  { "as_strided-size-stride-1", 60 },
  { "asin-1", 61 },
  { "atan-1", 62 },
  { "baddbmm-alpha-beta-3", 63 },
  { "baddbmm-beta-3", 64 },
  { "baddbmm-3", 65 },
  { "batch_norm-cudnn_enabled-eps-momentum-training-5", 66 },
  { "_batch_norm_impl_index-cudnn_enabled-eps-momentum-training-5", 67 },
  { "_batch_norm_impl_index_backward-eps-impl_index-output_mask-train-7", 68 },
  { "bernoulli-1", 69 },
  { "bernoulli-p-1", 70 },
  { "bilinear-4", 71 },
  { "binary_cross_entropy_with_logits-reduction-4", 72 },
  { "binary_cross_entropy_with_logits-4", 73 },
  { "binary_cross_entropy_with_logits-3", 74 },
  { "binary_cross_entropy_with_logits-2", 75 },
  { "binary_cross_entropy_with_logits_backward-reduction-5", 76 },
  { "binary_cross_entropy_with_logits_backward-5", 77 },
  { "binary_cross_entropy_with_logits_backward-4", 78 },
  { "binary_cross_entropy_with_logits_backward-3", 79 },
  { "bincount-minlength-2", 80 },
  { "bincount-2", 81 },
  { "bincount-1", 82 },
  { "bitwise_not-1", 83 },
  { "logical_not-1", 84 },
  { "logical_xor-2", 85 },
  { "bmm-2", 86 },
  { "broadcast_tensors-*", 87 },
  { "cat-dim-*", 88 },
  { "cat-*", 89 },
  { "ceil-1", 90 },
  { "chain_matmul-*", 91 },
  { "chunk-chunks-dim-1", 92 },
  { "chunk-chunks-1", 93 },
  { "clamp-1", 94 },
  { "clamp_max-max-1", 95 },
  { "clamp_min-min-1", 96 },
  { "cudnn_is_acceptable-1", 97 },
  { "constant_pad_nd-pad-value-1", 98 },
  { "constant_pad_nd-pad-1", 99 },
  { "contiguous-1", 100 },
  { "convolution-dilation-groups-output_padding-padding-stride-transposed-3", 101 },
  { "_convolution-benchmark-cudnn_enabled-deterministic-dilation-groups-output_padding-padding-stride-transposed-3", 102 },
  { "_convolution_nogroup-dilation-output_padding-padding-stride-transposed-3", 103 },
  { "_convolution_double_backward-benchmark-cudnn_enabled-deterministic-dilation-groups-output_mask-output_padding-padding-stride-transposed-6", 104 },
  { "conv1d-dilation-groups-padding-stride-3", 105 },
  { "conv1d-dilation-padding-stride-3", 106 },
  { "conv1d-padding-stride-3", 107 },
  { "conv1d-stride-3", 108 },
  { "conv1d-3", 109 },
  { "conv1d-2", 110 },
  { "conv2d-dilation-groups-padding-stride-3", 111 },
  { "conv2d-dilation-padding-stride-3", 112 },
  { "conv2d-padding-stride-3", 113 },
  { "conv2d-stride-3", 114 },
  { "conv2d-3", 115 },
  { "conv2d-2", 116 },
  { "conv3d-dilation-groups-padding-stride-3", 117 },
  { "conv3d-dilation-padding-stride-3", 118 },
  { "conv3d-padding-stride-3", 119 },
  { "conv3d-stride-3", 120 },
  { "conv3d-3", 121 },
  { "conv3d-2", 122 },
  { "conv_tbc-pad-3", 123 },
  { "conv_tbc-3", 124 },
  { "conv_tbc_backward-pad-4", 125 },
  { "conv_transpose1d-dilation-groups-output_padding-padding-stride-3", 126 },
  { "conv_transpose1d-groups-output_padding-padding-stride-3", 127 },
  { "conv_transpose1d-output_padding-padding-stride-3", 128 },
  { "conv_transpose1d-padding-stride-3", 129 },
  { "conv_transpose1d-stride-3", 130 },
  { "conv_transpose1d-3", 131 },
  { "conv_transpose1d-2", 132 },
  { "conv_transpose2d-dilation-groups-output_padding-padding-stride-3", 133 },
  { "conv_transpose2d-groups-output_padding-padding-stride-3", 134 },
  { "conv_transpose2d-output_padding-padding-stride-3", 135 },
  { "conv_transpose2d-padding-stride-3", 136 },
  { "conv_transpose2d-stride-3", 137 },
  { "conv_transpose2d-3", 138 },
  { "conv_transpose2d-2", 139 },
  { "conv_transpose3d-dilation-groups-output_padding-padding-stride-3", 140 },
  { "conv_transpose3d-groups-output_padding-padding-stride-3", 141 },
  { "conv_transpose3d-output_padding-padding-stride-3", 142 },
  { "conv_transpose3d-padding-stride-3", 143 },
  { "conv_transpose3d-stride-3", 144 },
  { "conv_transpose3d-3", 145 },
  { "conv_transpose3d-2", 146 },
  { "_copy_from-non_blocking-2", 147 },
  { "_copy_from-2", 148 },
  { "cos-1", 149 },
  { "cosh-1", 150 },
  { "cosine_embedding_loss-margin-reduction-3", 151 },
  { "cosine_embedding_loss-margin-3", 152 },
  { "cosine_embedding_loss-3", 153 },
  { "cudnn_affine_grid_generator-C-H-N-W-1", 154 },
  { "cudnn_affine_grid_generator_backward-C-H-N-W-1", 155 },
  { "cudnn_batch_norm-epsilon-exponential_average_factor-training-5", 156 },
  { "cudnn_batch_norm_backward-epsilon-7", 157 },
  { "cudnn_convolution-benchmark-deterministic-dilation-groups-padding-stride-3", 158 },
  { "cudnn_convolution_backward_input-benchmark-deterministic-dilation-groups-padding-self_size-stride-2", 159 },
  { "cudnn_convolution_backward-benchmark-deterministic-dilation-groups-output_mask-padding-stride-3", 160 },
  { "cudnn_convolution_backward_bias-1", 161 },
  { "cudnn_convolution_backward_weight-benchmark-deterministic-dilation-groups-padding-stride-weight_size-2", 162 },
  { "cudnn_convolution_transpose-benchmark-deterministic-dilation-groups-output_padding-padding-stride-3", 163 },
  { "cudnn_convolution_transpose_backward-benchmark-deterministic-dilation-groups-output_mask-output_padding-padding-stride-3", 164 },
  { "cudnn_convolution_transpose_backward_bias-1", 165 },
  { "cudnn_convolution_transpose_backward_input-benchmark-deterministic-dilation-groups-padding-stride-2", 166 },
  { "cudnn_convolution_transpose_backward_weight-benchmark-deterministic-dilation-groups-padding-stride-weight_size-2", 167 },
  { "cudnn_grid_sampler-2", 168 },
  { "cudnn_grid_sampler_backward-3", 169 },
  { "cumsum-dim-1", 170 },
  { "cumprod-dim-1", 171 },
  { "ctc_loss-blank-input_lengths-reduction-target_lengths-zero_infinity-2", 172 },
  { "ctc_loss-blank-input_lengths-reduction-target_lengths-2", 173 },
  { "ctc_loss-blank-input_lengths-target_lengths-2", 174 },
  { "ctc_loss-input_lengths-target_lengths-2", 175 },
  { "ctc_loss-blank-reduction-zero_infinity-4", 176 },
  { "ctc_loss-blank-reduction-4", 177 },
  { "ctc_loss-blank-4", 178 },
  { "ctc_loss-4", 179 },
  { "_ctc_loss-blank-input_lengths-target_lengths-zero_infinity-2", 180 },
  { "_ctc_loss-blank-input_lengths-target_lengths-2", 181 },
  { "_ctc_loss-input_lengths-target_lengths-2", 182 },
  { "_ctc_loss_backward-blank-input_lengths-target_lengths-zero_infinity-5", 183 },
  { "_ctc_loss_backward-blank-input_lengths-target_lengths-5", 184 },
  { "det-1", 185 },
  { "diag_embed-dim1-dim2-offset-1", 186 },
  { "diag_embed-dim1-offset-1", 187 },
  { "diag_embed-offset-1", 188 },
  { "diag_embed-1", 189 },
  { "diagflat-offset-1", 190 },
  { "diagflat-1", 191 },
  { "diagonal-dim1-dim2-offset-1", 192 },
  { "diagonal-dim1-offset-1", 193 },
  { "diagonal-offset-1", 194 },
  { "diagonal-1", 195 },
  { "div-2", 196 },
  { "div-other-1", 197 },
  { "dot-2", 198 },
  { "embedding-padding_idx-scale_grad_by_freq-sparse-2", 199 },
  { "embedding-padding_idx-scale_grad_by_freq-2", 200 },
  { "embedding-padding_idx-2", 201 },
  { "embedding-2", 202 },
  { "embedding_backward-num_weights-padding_idx-scale_grad_by_freq-sparse-2", 203 },
  { "embedding_dense_backward-num_weights-padding_idx-scale_grad_by_freq-2", 204 },
  { "embedding_sparse_backward-num_weights-padding_idx-scale_grad_by_freq-2", 205 },
  { "embedding_bag-mode-scale_grad_by_freq-sparse-4", 206 },
  { "embedding_bag-mode-scale_grad_by_freq-sparse-3", 207 },
  { "embedding_bag-mode-scale_grad_by_freq-3", 208 },
  { "embedding_bag-scale_grad_by_freq-3", 209 },
  { "embedding_bag-3", 210 },
  { "_embedding_bag-mode-scale_grad_by_freq-sparse-4", 211 },
  { "_embedding_bag-mode-scale_grad_by_freq-sparse-3", 212 },
  { "_embedding_bag-mode-scale_grad_by_freq-3", 213 },
  { "_embedding_bag-scale_grad_by_freq-3", 214 },
  { "_embedding_bag-3", 215 },
  { "_embedding_bag_backward-mode-num_weights-scale_grad_by_freq-sparse-7", 216 },
  { "_embedding_bag_sparse_backward-mode-num_weights-scale_grad_by_freq-6", 217 },
  { "_embedding_bag_dense_backward-mode-num_weights-scale_grad_by_freq-7", 218 },
  { "_embedding_bag_per_sample_weights_backward-mode-5", 219 },
  { "erf-1", 220 },
  { "erfc-1", 221 },
  { "exp-1", 222 },
  { "expm1-1", 223 },
  { "expand-implicit-size-1", 224 },
  { "expand-size-1", 225 },
  { "expand_as-2", 226 },
  { "flatten-end_dim-start_dim-1", 227 },
  { "flatten-start_dim-1", 228 },
  { "flatten-1", 229 },
  { "floor-1", 230 },
  { "frac-1", 231 },
  { "grid_sampler-interpolation_mode-padding_mode-2", 232 },
  { "grid_sampler_2d-interpolation_mode-padding_mode-2", 233 },
  { "grid_sampler_2d_backward-interpolation_mode-padding_mode-3", 234 },
  { "grid_sampler_3d-interpolation_mode-padding_mode-2", 235 },
  { "grid_sampler_3d_backward-interpolation_mode-padding_mode-3", 236 },
  { "hinge_embedding_loss-margin-reduction-2", 237 },
  { "hinge_embedding_loss-margin-2", 238 },
  { "hinge_embedding_loss-2", 239 },
  { "ger-2", 240 },
  { "group_norm-cudnn_enabled-eps-num_groups-3", 241 },
  { "group_norm-eps-num_groups-3", 242 },
  { "group_norm-num_groups-3", 243 },
  { "group_norm-num_groups-2", 244 },
  { "group_norm-num_groups-1", 245 },
  { "fft-normalized-signal_ndim-1", 246 },
  { "fft-signal_ndim-1", 247 },
  { "ifft-normalized-signal_ndim-1", 248 },
  { "ifft-signal_ndim-1", 249 },
  { "rfft-normalized-onesided-signal_ndim-1", 250 },
  { "rfft-normalized-signal_ndim-1", 251 },
  { "rfft-signal_ndim-1", 252 },
  { "irfft-normalized-onesided-signal_ndim-signal_sizes-1", 253 },
  { "irfft-normalized-onesided-signal_ndim-1", 254 },
  { "irfft-normalized-signal_ndim-1", 255 },
  { "irfft-signal_ndim-1", 256 },
  { "_fft_with_size-checked_signal_sizes-complex_input-complex_output-inverse-normalized-onesided-output_sizes-signal_ndim-1", 257 },
  { "_cufft_get_plan_cache_size-device_index-0", 258 },
  { "_cufft_get_plan_cache_max_size-device_index-0", 259 },
  { "index-*", 260 },
  { "index_copy-dim-3", 261 },
  { "index_put-accumulate-*", 262 },
  { "index_put-*", 263 },
  { "instance_norm-cudnn_enabled-eps-momentum-use_input_stats-5", 264 },
  { "inverse-1", 265 },
  { "_inverse_helper-1", 266 },
  { "isclose-atol-equal_nan-rtol-2", 267 },
  { "isclose-atol-rtol-2", 268 },
  { "isclose-rtol-2", 269 },
  { "isclose-2", 270 },
  { "isnan-1", 271 },
  { "is_distributed-1", 272 },
  { "is_floating_point-1", 273 },
  { "is_complex-1", 274 },
  { "is_nonzero-1", 275 },
  { "is_same_size-2", 276 },
  { "is_signed-1", 277 },
  { "kl_div-reduction-2", 278 },
  { "kl_div-2", 279 },
  { "kl_div_backward-reduction-3", 280 },
  { "kl_div_backward-3", 281 },
  { "kthvalue-dim-k-keepdim-1", 282 },
  { "kthvalue-dim-k-1", 283 },
  { "kthvalue-k-1", 284 },
  { "layer_norm-cudnn_enable-eps-normalized_shape-3", 285 },
  { "layer_norm-eps-normalized_shape-3", 286 },
  { "layer_norm-normalized_shape-3", 287 },
  { "layer_norm-normalized_shape-2", 288 },
  { "layer_norm-normalized_shape-1", 289 },
  { "native_layer_norm-M-N-eps-3", 290 },
  { "native_layer_norm_backward-M-N-output_mask-5", 291 },
  { "native_layer_norm_double_backward-M-N-output_mask-8", 292 },
  { "linear-3", 293 },
  { "linear-2", 294 },
  { "mkldnn_linear-3", 295 },
  { "mkldnn_linear-2", 296 },
  { "fbgemm_linear_int8_weight_fp32_activation-weight_scale-weight_zero_point-5", 297 },
  { "fbgemm_linear_int8_weight-weight_scale-weight_zero_point-5", 298 },
  { "fbgemm_pack_gemm_matrix_fp16-1", 299 },
  { "fbgemm_linear_fp16_weight_fp32_activation-3", 300 },
  { "fbgemm_linear_fp16_weight-3", 301 },
  { "fbgemm_pack_quantized_matrix-1", 302 },
  { "fbgemm_pack_quantized_matrix-K-N-1", 303 },
  { "fbgemm_is_cpu_supported-0", 304 },
  { "log-1", 305 },
  { "log10-1", 306 },
  { "log1p-1", 307 },
  { "log2-1", 308 },
  { "logdet-1", 309 },
  { "log_softmax-dim-1", 310 },
  { "_log_softmax-dim-half_to_float-1", 311 },
  { "_log_softmax_backward_data-dim-3", 312 },
  { "logsumexp-dim-keepdim-1", 313 },
  { "logsumexp-dim-1", 314 },
  { "margin_ranking_loss-margin-reduction-3", 315 },
  { "margin_ranking_loss-margin-3", 316 },
  { "margin_ranking_loss-3", 317 },
  { "matmul-2", 318 },
  { "matrix_rank-symmetric-tol-1", 319 },
  { "matrix_rank-tol-1", 320 },
  { "matrix_rank-symmetric-1", 321 },
  { "matrix_rank-1", 322 },
  { "matrix_power-n-1", 323 },
  { "max-dim-keepdim-1", 324 },
  { "max-dim-1", 325 },
  { "max_values-dim-keepdim-1", 326 },
  { "max_values-dim-1", 327 },
  { "max_pool1d_with_indices-ceil_mode-dilation-kernel_size-padding-stride-1", 328 },
  { "max_pool1d_with_indices-dilation-kernel_size-padding-stride-1", 329 },
  { "max_pool1d_with_indices-kernel_size-padding-stride-1", 330 },
  { "max_pool1d_with_indices-kernel_size-stride-1", 331 },
  { "max_pool1d_with_indices-kernel_size-1", 332 },
  { "max_pool1d-ceil_mode-dilation-kernel_size-padding-stride-1", 333 },
  { "max_pool1d-dilation-kernel_size-padding-stride-1", 334 },
  { "max_pool1d-kernel_size-padding-stride-1", 335 },
  { "max_pool1d-kernel_size-stride-1", 336 },
  { "max_pool1d-kernel_size-1", 337 },
  { "max_pool2d-ceil_mode-dilation-kernel_size-padding-stride-1", 338 },
  { "max_pool2d-dilation-kernel_size-padding-stride-1", 339 },
  { "max_pool2d-kernel_size-padding-stride-1", 340 },
  { "max_pool2d-kernel_size-stride-1", 341 },
  { "max_pool2d-kernel_size-1", 342 },
  { "mkldnn_max_pool2d-ceil_mode-dilation-kernel_size-padding-stride-1", 343 },
  { "mkldnn_max_pool2d-dilation-kernel_size-padding-stride-1", 344 },
  { "mkldnn_max_pool2d-kernel_size-padding-stride-1", 345 },
  { "mkldnn_max_pool2d-kernel_size-stride-1", 346 },
  { "mkldnn_max_pool2d-kernel_size-1", 347 },
  { "quantized_max_pool2d-dilation-kernel_size-padding-stride-1", 348 },
  { "quantized_max_pool2d-kernel_size-padding-stride-1", 349 },
  { "quantized_max_pool2d-kernel_size-stride-1", 350 },
  { "quantized_max_pool2d-kernel_size-1", 351 },
  { "max_pool3d-ceil_mode-dilation-kernel_size-padding-stride-1", 352 },
  { "max_pool3d-dilation-kernel_size-padding-stride-1", 353 },
  { "max_pool3d-kernel_size-padding-stride-1", 354 },
  { "max_pool3d-kernel_size-stride-1", 355 },
  { "max_pool3d-kernel_size-1", 356 },
  { "mean-1", 357 },
  { "mean-dim-keepdim-1", 358 },
  { "mean-dim-1", 359 },
  { "median-dim-keepdim-1", 360 },
  { "median-dim-1", 361 },
  { "min-dim-keepdim-1", 362 },
  { "min-dim-1", 363 },
  { "min_values-dim-keepdim-1", 364 },
  { "min_values-dim-1", 365 },
  { "mkldnn_convolution-dilation-groups-padding-stride-3", 366 },
  { "mkldnn_convolution_backward_input-bias_defined-dilation-groups-padding-self_size-stride-2", 367 },
  { "mkldnn_convolution_backward_weights-bias_defined-dilation-groups-padding-stride-weight_size-2", 368 },
  { "mkldnn_convolution_backward-dilation-groups-output_mask-padding-stride-3", 369 },
  { "miopen_batch_norm-epsilon-exponential_average_factor-training-5", 370 },
  { "miopen_batch_norm_backward-epsilon-7", 371 },
  { "miopen_convolution-benchmark-deterministic-dilation-groups-padding-stride-3", 372 },
  { "miopen_convolution_backward_input-benchmark-deterministic-dilation-groups-padding-self_size-stride-2", 373 },
  { "miopen_convolution_backward-benchmark-deterministic-dilation-groups-output_mask-padding-stride-3", 374 },
  { "miopen_convolution_backward_bias-1", 375 },
  { "miopen_convolution_backward_weight-benchmark-deterministic-dilation-groups-padding-stride-weight_size-2", 376 },
  { "miopen_convolution_transpose-benchmark-deterministic-dilation-groups-output_padding-padding-stride-3", 377 },
  { "miopen_convolution_transpose_backward-benchmark-deterministic-dilation-groups-output_mask-output_padding-padding-stride-3", 378 },
  { "miopen_convolution_transpose_backward_input-benchmark-deterministic-dilation-groups-padding-stride-2", 379 },
  { "miopen_convolution_transpose_backward_weight-benchmark-deterministic-dilation-groups-padding-stride-weight_size-2", 380 },
  { "miopen_depthwise_convolution-benchmark-deterministic-dilation-groups-padding-stride-3", 381 },
  { "miopen_depthwise_convolution_backward_input-benchmark-deterministic-dilation-groups-padding-self_size-stride-2", 382 },
  { "miopen_depthwise_convolution_backward-benchmark-deterministic-dilation-groups-output_mask-padding-stride-3", 383 },
  { "miopen_depthwise_convolution_backward_weight-benchmark-deterministic-dilation-groups-padding-stride-weight_size-2", 384 },
  { "miopen_rnn-batch_first-batch_sizes-bidirectional-dropout-hidden_size-mode-num_layers-train-weight_stride0-*", 385 },
  { "mm-2", 386 },
  { "_sparse_mm-2", 387 },
  { "mode-dim-keepdim-1", 388 },
  { "mode-dim-1", 389 },
  { "mode-1", 390 },
  { "mul-2", 391 },
  { "mul-other-1", 392 },
  { "mv-2", 393 },
  { "mvlgamma-p-1", 394 },
  { "narrow_copy-dim-length-start-1", 395 },
  { "narrow-dim-length-start-1", 396 },
  { "native_batch_norm-eps-momentum-training-5", 397 },
  { "batch_norm_stats-eps-1", 398 },
  { "batch_norm_elemt-eps-5", 399 },
  { "batch_norm_gather_stats-count-eps-momentum-5", 400 },
  { "batch_norm_gather_stats_with_counts-counts-eps-momentum-5", 401 },
  { "native_batch_norm_backward-eps-output_mask-train-7", 402 },
  { "batch_norm_backward_reduce-bias_g-input_g-weight_g-4", 403 },
  { "batch_norm_backward_elemt-7", 404 },
  { "batch_norm_update_stats-momentum-3", 405 },
  { "_nnpack_available-0", 406 },
  { "_nnpack_spatial_convolution-padding-3", 407 },
  { "_nnpack_spatial_convolution_backward-output_mask-padding-3", 408 },
  { "_nnpack_spatial_convolution_backward_input-padding-3", 409 },
  { "_nnpack_spatial_convolution_backward_weight-padding-weightsize-2", 410 },
  { "pairwise_distance-eps-keepdim-p-2", 411 },
  { "pairwise_distance-eps-p-2", 412 },
  { "pairwise_distance-p-2", 413 },
  { "pairwise_distance-2", 414 },
  { "cdist-p-2", 415 },
  { "cdist-2", 416 },
  { "_cdist_backward-p-4", 417 },
  { "pdist-p-1", 418 },
  { "pdist-1", 419 },
  { "_pdist_forward-p-1", 420 },
  { "_pdist_forward-1", 421 },
  { "_pdist_backward-p-3", 422 },
  { "cosine_similarity-dim-eps-2", 423 },
  { "cosine_similarity-dim-2", 424 },
  { "cosine_similarity-2", 425 },
  { "permute-dims-1", 426 },
  { "numpy_T-1", 427 },
  { "pixel_shuffle-upscale_factor-1", 428 },
  { "is_pinned-1", 429 },
  { "pin_memory-1", 430 },
  { "pinverse-rcond-1", 431 },
  { "pinverse-1", 432 },
  { "poisson_nll_loss-eps-full-log_input-reduction-2", 433 },
  { "reciprocal-1", 434 },
  { "neg-1", 435 },
  { "repeat-repeats-1", 436 },
  { "repeat_interleave-1", 437 },
  { "repeat_interleave-2", 438 },
  { "repeat_interleave-repeats-1", 439 },
  { "reshape-shape-1", 440 },
  { "_mkldnn_reshape-shape-1", 441 },
  { "reshape_as-2", 442 },
  { "round-1", 443 },
  { "rrelu-lower-training-upper-1", 444 },
  { "rrelu-lower-upper-1", 445 },
  { "rrelu-lower-1", 446 },
  { "rrelu-1", 447 },
  { "relu-1", 448 },
  { "prelu-2", 449 },
  { "prelu_backward-3", 450 },
  { "gelu-1", 451 },
  { "gelu_backward-2", 452 },
  { "hardshrink-lambd-1", 453 },
  { "hardshrink-1", 454 },
  { "hardshrink_backward-lambd-2", 455 },
  { "rsqrt-1", 456 },
  { "select-dim-index-1", 457 },
  { "selu-1", 458 },
  { "celu-alpha-1", 459 },
  { "celu-1", 460 },
  { "sigmoid-1", 461 },
  { "sin-1", 462 },
  { "sinh-1", 463 },
  { "detach-1", 464 },
  { "size-dim-1", 465 },
  { "slice-dim-end-start-step-1", 466 },
  { "slice-dim-end-start-1", 467 },
  { "slice-dim-start-1", 468 },
  { "slice-dim-1", 469 },
  { "slice-1", 470 },
  { "slogdet-1", 471 },
  { "smm-2", 472 },
  { "softmax-dim-1", 473 },
  { "_softmax-dim-half_to_float-1", 474 },
  { "_softmax_backward_data-dim-3", 475 },
  { "split-dim-split_size-1", 476 },
  { "split-split_size-1", 477 },
  { "split_with_sizes-dim-split_sizes-1", 478 },
  { "split_with_sizes-split_sizes-1", 479 },
  { "squeeze-1", 480 },
  { "squeeze-dim-1", 481 },
  { "sspaddmm-alpha-beta-3", 482 },
  { "sspaddmm-beta-3", 483 },
  { "sspaddmm-3", 484 },
  { "stack-dim-*", 485 },
  { "stack-*", 486 },
  { "stft-n_fft-1", 487 },
  { "stride-dim-1", 488 },
  { "sum-1", 489 },
  { "sum-dim-keepdim-1", 490 },
  { "sum-dim-1", 491 },
  { "sum_to_size-size-1", 492 },
  { "sqrt-1", 493 },
  { "std-unbiased-1", 494 },
  { "std-1", 495 },
  { "std-dim-keepdim-unbiased-1", 496 },
  { "std-dim-unbiased-1", 497 },
  { "std-dim-1", 498 },
  { "std_mean-unbiased-1", 499 },
  { "std_mean-1", 500 },
  { "std_mean-dim-keepdim-unbiased-1", 501 },
  { "std_mean-dim-unbiased-1", 502 },
  { "std_mean-dim-1", 503 },
  { "prod-1", 504 },
  { "prod-dim-keepdim-1", 505 },
  { "prod-dim-1", 506 },
  { "t-1", 507 },
  { "tan-1", 508 },
  { "tanh-1", 509 },
  { "tensordot-dims_other-dims_self-2", 510 },
  { "threshold-threshold-value-1", 511 },
  { "threshold_backward-threshold-2", 512 },
  { "transpose-dim0-dim1-1", 513 },
  { "_mkldnn_transpose-dim0-dim1-1", 514 },
  { "one_hot-num_classes-1", 515 },
  { "one_hot-1", 516 },
  { "flip-dims-1", 517 },
  { "roll-dims-shifts-1", 518 },
  { "roll-shifts-1", 519 },
  { "rot90-dims-k-1", 520 },
  { "rot90-k-1", 521 },
  { "rot90-1", 522 },
  { "trapz-dim-2", 523 },
  { "trapz-2", 524 },
  { "trapz-dim-dx-1", 525 },
  { "trapz-dx-1", 526 },
  { "trapz-1", 527 },
  { "_trilinear-expand1-expand2-expand3-sumdim-unroll_dim-3", 528 },
  { "_trilinear-expand1-expand2-expand3-sumdim-3", 529 },
  { "triplet_margin_loss-eps-margin-p-reduction-swap-3", 530 },
  { "triplet_margin_loss-eps-margin-p-swap-3", 531 },
  { "triplet_margin_loss-eps-margin-p-3", 532 },
  { "triplet_margin_loss-margin-p-3", 533 },
  { "triplet_margin_loss-margin-3", 534 },
  { "triplet_margin_loss-3", 535 },
  { "trunc-1", 536 },
  { "type_as-2", 537 },
  { "_has_compatible_shallow_copy_type-2", 538 },
  { "_unique-return_inverse-sorted-1", 539 },
  { "_unique-sorted-1", 540 },
  { "_unique-1", 541 },
  { "unique_dim-dim-return_counts-return_inverse-sorted-1", 542 },
  { "unique_dim-dim-return_inverse-sorted-1", 543 },
  { "unique_dim-dim-sorted-1", 544 },
  { "unique_dim-dim-1", 545 },
  { "unique_consecutive-return_counts-return_inverse-1", 546 },
  { "unique_consecutive-return_inverse-1", 547 },
  { "unique_consecutive-1", 548 },
  { "unique_dim_consecutive-dim-return_counts-return_inverse-1", 549 },
  { "unique_dim_consecutive-dim-return_inverse-1", 550 },
  { "unique_dim_consecutive-dim-1", 551 },
  { "_unique2-return_counts-return_inverse-sorted-1", 552 },
  { "_unique2-return_inverse-sorted-1", 553 },
  { "_unique2-sorted-1", 554 },
  { "_unique2-1", 555 },
  { "_unsafe_view-size-1", 556 },
  { "unsqueeze-dim-1", 557 },
  { "var-unbiased-1", 558 },
  { "var-1", 559 },
  { "var-dim-keepdim-unbiased-1", 560 },
  { "var-dim-unbiased-1", 561 },
  { "var-dim-1", 562 },
  { "var_mean-unbiased-1", 563 },
  { "var_mean-1", 564 },
  { "var_mean-dim-keepdim-unbiased-1", 565 },
  { "var_mean-dim-unbiased-1", 566 },
  { "var_mean-dim-1", 567 },
  { "view_as-2", 568 },
  { "where-3", 569 },
  { "where-1", 570 },
  { "_s_where-3", 571 },
  { "norm_except_dim-dim-pow-1", 572 },
  { "norm_except_dim-pow-1", 573 },
  { "norm_except_dim-1", 574 },
  { "_weight_norm-dim-2", 575 },
  { "_weight_norm-2", 576 },
  { "_weight_norm_cuda_interface-dim-2", 577 },
  { "_weight_norm_cuda_interface-2", 578 },
  { "_weight_norm_cuda_interface_backward-dim-4", 579 },
  { "_weight_norm_differentiable_backward-dim-4", 580 },
  { "_standard_gamma_grad-2", 581 },
  { "_standard_gamma-1", 582 },
  { "_dirichlet_grad-3", 583 },
  { "_sample_dirichlet-1", 584 },
  { "poisson-1", 585 },
  { "native_norm-p-1", 586 },
  { "native_norm-1", 587 },
  { "_sparse_sum-1", 588 },
  { "_sparse_sum-dim-1", 589 },
  { "_sparse_sum_backward-dim-2", 590 },
  { "norm-p-1", 591 },
  { "norm-1", 592 },
  { "frobenius_norm-1", 593 },
  { "frobenius_norm-dim-keepdim-1", 594 },
  { "frobenius_norm-dim-1", 595 },
  { "nuclear_norm-keepdim-1", 596 },
  { "nuclear_norm-1", 597 },
  { "nuclear_norm-dim-keepdim-1", 598 },
  { "nuclear_norm-dim-1", 599 },
  { "clone-1", 600 },
  { "pow-exponent-1", 601 },
  { "sub-alpha-2", 602 },
  { "sub-2", 603 },
  { "sub-alpha-other-1", 604 },
  { "sub-other-1", 605 },
  { "rsub-alpha-2", 606 },
  { "rsub-2", 607 },
  { "rsub-alpha-other-1", 608 },
  { "rsub-other-1", 609 },
  { "s_native_addmm-alpha-beta-3", 610 },
  { "s_native_addmm-beta-3", 611 },
  { "s_native_addmm-3", 612 },
  { "_sparse_addmm-alpha-beta-3", 613 },
  { "_sparse_addmm-beta-3", 614 },
  { "_sparse_addmm-3", 615 },
  { "addmm-alpha-beta-3", 616 },
  { "addmm-beta-3", 617 },
  { "addmm-3", 618 },
  { "sparse_mask-2", 619 },
  { "to_dense-1", 620 },
  { "to_dense_backward-2", 621 },
  { "sparse_dim-1", 622 },
  { "_dimI-1", 623 },
  { "dense_dim-1", 624 },
  { "_dimV-1", 625 },
  { "_nnz-1", 626 },
  { "coalesce-1", 627 },
  { "is_coalesced-1", 628 },
  { "_indices-1", 629 },
  { "_values-1", 630 },
  { "indices-1", 631 },
  { "values-1", 632 },
  { "hspmm-2", 633 },
  { "numel-1", 634 },
  { "unbind-dim-1", 635 },
  { "unbind-1", 636 },
  { "to_sparse-sparse_dim-1", 637 },
  { "to_sparse-1", 638 },
  { "to_mkldnn-1", 639 },
  { "mkldnn_reorder_conv2d_weight-dilation-groups-padding-stride-1", 640 },
  { "mkldnn_reorder_conv2d_weight-dilation-padding-stride-1", 641 },
  { "mkldnn_reorder_conv2d_weight-padding-stride-1", 642 },
  { "mkldnn_reorder_conv2d_weight-padding-1", 643 },
  { "mkldnn_reorder_conv2d_weight-1", 644 },
  { "to_mkldnn_backward-2", 645 },
  { "dequantize-1", 646 },
  { "q_zero_point-1", 647 },
  { "int_repr-1", 648 },
  { "_per_tensor_affine_qtensor-scale-zero_point-1", 649 },
  { "fake_quantize_per_tensor_affine-quant_max-quant_min-scale-zero_point-1", 650 },
  { "fake_quantize_per_tensor_affine_backward-quant_max-quant_min-scale-zero_point-2", 651 },
  { "meshgrid-*", 652 },
  { "cartesian_prod-*", 653 },
  { "combinations-r-with_replacement-1", 654 },
  { "combinations-r-1", 655 },
  { "combinations-1", 656 },
  { "item-1", 657 },
  { "_local_scalar_dense-1", 658 },
  { "_thnn_fused_lstm_cell-5", 659 },
  { "_thnn_fused_lstm_cell-4", 660 },
  { "_thnn_fused_lstm_cell-3", 661 },
  { "_thnn_fused_lstm_cell_backward-has_bias-5", 662 },
  { "_thnn_fused_gru_cell-5", 663 },
  { "_thnn_fused_gru_cell-4", 664 },
  { "_thnn_fused_gru_cell-3", 665 },
  { "_thnn_fused_gru_cell_backward-has_bias-2", 666 },
  { "lstm-batch_first-bidirectional-dropout-has_biases-num_layers-train-*", 667 },
  { "lstm-bidirectional-dropout-has_biases-num_layers-train-*", 668 },
  { "gru-batch_first-bidirectional-dropout-has_biases-num_layers-train-*", 669 },
  { "gru-bidirectional-dropout-has_biases-num_layers-train-*", 670 },
  { "rnn_tanh-batch_first-bidirectional-dropout-has_biases-num_layers-train-*", 671 },
  { "rnn_tanh-bidirectional-dropout-has_biases-num_layers-train-*", 672 },
  { "rnn_relu-batch_first-bidirectional-dropout-has_biases-num_layers-train-*", 673 },
  { "rnn_relu-bidirectional-dropout-has_biases-num_layers-train-*", 674 },
  { "lstm_cell-*", 675 },
  { "gru_cell-6", 676 },
  { "gru_cell-5", 677 },
  { "gru_cell-4", 678 },
  { "rnn_tanh_cell-6", 679 },
  { "rnn_tanh_cell-5", 680 },
  { "rnn_tanh_cell-4", 681 },
  { "rnn_relu_cell-6", 682 },
  { "rnn_relu_cell-5", 683 },
  { "rnn_relu_cell-4", 684 },
  { "quantized_lstm-batch_first-bidirectional-dropout-has_biases-num_layers-train-*", 685 },
  { "quantized_gru-batch_first-bidirectional-dropout-has_biases-num_layers-train-*", 686 },
  { "quantized_gru-bidirectional-dropout-has_biases-num_layers-train-*", 687 },
  { "quantized_lstm_cell-scale_hh-scale_ih-zero_point_hh-zero_point_ih-*", 688 },
  { "quantized_gru_cell-scale_hh-scale_ih-zero_point_hh-zero_point_ih-10", 689 },
  { "quantized_rnn_relu_cell-scale_hh-scale_ih-zero_point_hh-zero_point_ih-10", 690 },
  { "quantized_rnn_tanh_cell-scale_hh-scale_ih-zero_point_hh-zero_point_ih-10", 691 },
  { "_pack_padded_sequence-batch_first-2", 692 },
  { "_pack_padded_sequence_backward-batch_first-input_size-2", 693 },
  { "_pad_packed_sequence-batch_first-padding_value-total_length-2", 694 },
  { "is_set_to-2", 695 },
  { "masked_fill-value-2", 696 },
  { "masked_fill-3", 697 },
  { "masked_scatter-3", 698 },
  { "view-size-1", 699 },
  { "index_add-dim-3", 700 },
  { "index_fill-dim-value-2", 701 },
  { "index_fill-dim-3", 702 },
  { "scatter-dim-3", 703 },
  { "scatter-dim-value-2", 704 },
  { "scatter_add-dim-3", 705 },
  { "__and__-other-1", 706 },
  { "__and__-2", 707 },
  { "__or__-other-1", 708 },
  { "__or__-2", 709 },
  { "__xor__-other-1", 710 },
  { "__xor__-2", 711 },
  { "__lshift__-other-1", 712 },
  { "__lshift__-2", 713 },
  { "__rshift__-other-1", 714 },
  { "__rshift__-2", 715 },
  { "addbmm-alpha-beta-3", 716 },
  { "addbmm-beta-3", 717 },
  { "addbmm-3", 718 },
  { "diag-diagonal-1", 719 },
  { "diag-1", 720 },
  { "cross-2", 721 },
  { "triu-diagonal-1", 722 },
  { "triu-1", 723 },
  { "tril-diagonal-1", 724 },
  { "tril-1", 725 },
  { "trace-1", 726 },
  { "ne-other-1", 727 },
  { "ne-2", 728 },
  { "eq-other-1", 729 },
  { "eq-2", 730 },
  { "ge-other-1", 731 },
  { "ge-2", 732 },
  { "le-other-1", 733 },
  { "le-2", 734 },
  { "gt-other-1", 735 },
  { "gt-2", 736 },
  { "lt-other-1", 737 },
  { "lt-2", 738 },
  { "take-2", 739 },
  { "index_select-dim-2", 740 },
  { "masked_select-2", 741 },
  { "nonzero-1", 742 },
  { "nonzero_numpy-1", 743 },
  { "gather-dim-sparse_grad-2", 744 },
  { "gather-dim-2", 745 },
  { "_gather_sparse_backward-dim-3", 746 },
  { "addcmul-value-3", 747 },
  { "addcmul-3", 748 },
  { "addcdiv-value-3", 749 },
  { "addcdiv-3", 750 },
  { "lstsq-2", 751 },
  { "triangular_solve-transpose-unitriangular-upper-2", 752 },
  { "triangular_solve-transpose-upper-2", 753 },
  { "triangular_solve-upper-2", 754 },
  { "triangular_solve-2", 755 },
  { "_triangular_solve_helper-transpose-unitriangular-upper-2", 756 },
  { "symeig-eigenvectors-upper-1", 757 },
  { "symeig-eigenvectors-1", 758 },
  { "symeig-1", 759 },
  { "_symeig_helper-eigenvectors-upper-1", 760 },
  { "eig-eigenvectors-1", 761 },
  { "eig-1", 762 },
  { "svd-compute_uv-some-1", 763 },
  { "svd-some-1", 764 },
  { "svd-1", 765 },
  { "_svd_helper-compute_uv-some-1", 766 },
  { "cholesky-upper-1", 767 },
  { "cholesky-1", 768 },
  { "_cholesky_helper-upper-1", 769 },
  { "cholesky_solve-upper-2", 770 },
  { "cholesky_solve-2", 771 },
  { "_cholesky_solve_helper-upper-2", 772 },
  { "solve-2", 773 },
  { "_solve_helper-2", 774 },
  { "cholesky_inverse-upper-1", 775 },
  { "cholesky_inverse-1", 776 },
  { "qr-some-1", 777 },
  { "qr-1", 778 },
  { "_qr_helper-some-1", 779 },
  { "geqrf-1", 780 },
  { "orgqr-2", 781 },
  { "ormqr-left-transpose-3", 782 },
  { "ormqr-left-3", 783 },
  { "ormqr-3", 784 },
  { "_lu_with_info-check_errors-pivot-1", 785 },
  { "_lu_with_info-pivot-1", 786 },
  { "_lu_with_info-1", 787 },
  { "lu_solve-3", 788 },
  { "_lu_solve_helper-3", 789 },
  { "multinomial-num_samples-replacement-1", 790 },
  { "multinomial-num_samples-1", 791 },
  { "_multinomial_alias_setup-1", 792 },
  { "_multinomial_alias_draw-num_samples-2", 793 },
  { "lgamma-1", 794 },
  { "digamma-1", 795 },
  { "polygamma-n-1", 796 },
  { "erfinv-1", 797 },
  { "dist-p-2", 798 },
  { "dist-2", 799 },
  { "atan2-2", 800 },
  { "lerp-weight-2", 801 },
  { "lerp-3", 802 },
  { "histc-bins-max-min-1", 803 },
  { "histc-bins-min-1", 804 },
  { "histc-bins-1", 805 },
  { "histc-1", 806 },
  { "sign-1", 807 },
  { "fmod-other-1", 808 },
  { "fmod-2", 809 },
  { "remainder-other-1", 810 },
  { "remainder-2", 811 },
  { "min-2", 812 },
  { "min-1", 813 },
  { "max-2", 814 },
  { "max-1", 815 },
  { "median-1", 816 },
  { "sort-descending-dim-1", 817 },
  { "sort-dim-1", 818 },
  { "sort-1", 819 },
  { "argsort-descending-dim-1", 820 },
  { "argsort-dim-1", 821 },
  { "argsort-1", 822 },
  { "topk-dim-k-largest-sorted-1", 823 },
  { "topk-dim-k-largest-1", 824 },
  { "topk-dim-k-1", 825 },
  { "topk-k-1", 826 },
  { "all-1", 827 },
  { "any-1", 828 },
  { "renorm-dim-maxnorm-p-1", 829 },
  { "unfold-dimension-size-step-1", 830 },
  { "equal-2", 831 },
  { "pow-2", 832 },
  { "pow-self-1", 833 },
  { "alias-1", 834 },
  { "_addr-alpha-beta-3", 835 },
  { "_addr-beta-3", 836 },
  { "_addr-3", 837 },
  { "_cumsum-dim-1", 838 },
  { "_cumprod-dim-1", 839 },
  { "_var-unbiased-1", 840 },
  { "_var-1", 841 },
  { "_std-unbiased-1", 842 },
  { "_std-1", 843 },
  { "_addmm-alpha-beta-3", 844 },
  { "_addmm-beta-3", 845 },
  { "_addmm-3", 846 },
  { "_cat-dim-*", 847 },
  { "_cat-*", 848 },
  { "_mode-dim-keepdim-1", 849 },
  { "_mode-dim-1", 850 },
  { "_mode-1", 851 },
  { "_max-dim-keepdim-1", 852 },
  { "_max-dim-1", 853 },
  { "_min-dim-keepdim-1", 854 },
  { "_min-dim-1", 855 },
  { "binary_cross_entropy-reduction-3", 856 },
  { "binary_cross_entropy-3", 857 },
  { "binary_cross_entropy-2", 858 },
  { "binary_cross_entropy_backward-reduction-4", 859 },
  { "binary_cross_entropy_backward-4", 860 },
  { "binary_cross_entropy_backward-3", 861 },
  { "mse_loss-reduction-2", 862 },
  { "mse_loss-2", 863 },
  { "mse_loss_backward-reduction-3", 864 },
  { "l1_loss-reduction-2", 865 },
  { "l1_loss-2", 866 },
  { "l1_loss_backward-reduction-3", 867 },
  { "multi_margin_loss-margin-p-reduction-3", 868 },
  { "multi_margin_loss-margin-p-3", 869 },
  { "multi_margin_loss-margin-p-2", 870 },
  { "multi_margin_loss-p-2", 871 },
  { "multi_margin_loss-2", 872 },
  { "multi_margin_loss_backward-margin-p-reduction-4", 873 },
  { "multi_margin_loss_backward-margin-p-4", 874 },
  { "multi_margin_loss_backward-margin-p-3", 875 },
  { "multilabel_margin_loss-reduction-2", 876 },
  { "multilabel_margin_loss-2", 877 },
  { "multilabel_margin_loss_forward-reduction-2", 878 },
  { "multilabel_margin_loss_backward-reduction-4", 879 },
  { "nll_loss-ignore_index-reduction-3", 880 },
  { "nll_loss-reduction-3", 881 },
  { "nll_loss-3", 882 },
  { "nll_loss-2", 883 },
  { "nll_loss_forward-ignore_index-reduction-3", 884 },
  { "nll_loss_backward-ignore_index-reduction-5", 885 },
  { "nll_loss2d-ignore_index-reduction-3", 886 },
  { "nll_loss2d-reduction-3", 887 },
  { "nll_loss2d-3", 888 },
  { "nll_loss2d-2", 889 },
  { "nll_loss2d_forward-ignore_index-reduction-3", 890 },
  { "nll_loss2d_backward-ignore_index-reduction-5", 891 },
  { "smooth_l1_loss-reduction-2", 892 },
  { "smooth_l1_loss-2", 893 },
  { "smooth_l1_loss_backward-reduction-3", 894 },
  { "soft_margin_loss-reduction-2", 895 },
  { "soft_margin_loss-2", 896 },
  { "soft_margin_loss_backward-reduction-3", 897 },
  { "elu-alpha-input_scale-scale-1", 898 },
  { "elu-alpha-scale-1", 899 },
  { "elu-alpha-1", 900 },
  { "elu-1", 901 },
  { "elu_backward-alpha-input_scale-scale-2", 902 },
  { "glu-dim-1", 903 },
  { "glu-1", 904 },
  { "glu_backward-dim-2", 905 },
  { "hardtanh-max_val-min_val-1", 906 },
  { "hardtanh-min_val-1", 907 },
  { "hardtanh-1", 908 },
  { "hardtanh_backward-max_val-min_val-2", 909 },
  { "leaky_relu-negative_slope-1", 910 },
  { "leaky_relu-1", 911 },
  { "leaky_relu_backward-negative_slope-2", 912 },
  { "log_sigmoid-1", 913 },
  { "log_sigmoid_forward-1", 914 },
  { "log_sigmoid_backward-3", 915 },
  { "rrelu_with_noise-lower-training-upper-2", 916 },
  { "rrelu_with_noise-lower-upper-2", 917 },
  { "rrelu_with_noise-lower-2", 918 },
  { "rrelu_with_noise-2", 919 },
  { "rrelu_with_noise_backward-lower-training-upper-3", 920 },
  { "softplus-beta-threshold-1", 921 },
  { "softplus-beta-1", 922 },
  { "softplus-1", 923 },
  { "softplus_backward-beta-threshold-3", 924 },
  { "softshrink-lambd-1", 925 },
  { "softshrink-1", 926 },
  { "softshrink_backward-lambd-2", 927 },
  { "adaptive_avg_pool2d-output_size-1", 928 },
  { "mkldnn_adaptive_avg_pool2d-output_size-1", 929 },
  { "_adaptive_avg_pool2d-output_size-1", 930 },
  { "_adaptive_avg_pool2d_backward-2", 931 },
  { "adaptive_avg_pool3d-output_size-1", 932 },
  { "adaptive_avg_pool3d_backward-2", 933 },
  { "adaptive_max_pool2d-output_size-1", 934 },
  { "adaptive_max_pool2d_backward-3", 935 },
  { "adaptive_max_pool3d-output_size-1", 936 },
  { "adaptive_max_pool3d_backward-3", 937 },
  { "avg_pool2d-ceil_mode-count_include_pad-kernel_size-padding-stride-1", 938 },
  { "avg_pool2d-ceil_mode-kernel_size-padding-stride-1", 939 },
  { "avg_pool2d-kernel_size-padding-stride-1", 940 },
  { "avg_pool2d-kernel_size-stride-1", 941 },
  { "avg_pool2d-kernel_size-1", 942 },
  { "avg_pool3d-ceil_mode-count_include_pad-kernel_size-padding-stride-1", 943 },
  { "avg_pool3d-ceil_mode-kernel_size-padding-stride-1", 944 },
  { "avg_pool3d-kernel_size-padding-stride-1", 945 },
  { "avg_pool3d-kernel_size-stride-1", 946 },
  { "avg_pool3d-kernel_size-1", 947 },
  { "fractional_max_pool2d-kernel_size-output_size-2", 948 },
  { "fractional_max_pool2d_backward-kernel_size-output_size-3", 949 },
  { "fractional_max_pool3d-kernel_size-output_size-2", 950 },
  { "fractional_max_pool3d_backward-kernel_size-output_size-3", 951 },
  { "max_pool2d_with_indices-ceil_mode-dilation-kernel_size-padding-stride-1", 952 },
  { "max_pool2d_with_indices-dilation-kernel_size-padding-stride-1", 953 },
  { "max_pool2d_with_indices-kernel_size-padding-stride-1", 954 },
  { "max_pool2d_with_indices-kernel_size-stride-1", 955 },
  { "max_pool2d_with_indices-kernel_size-1", 956 },
  { "max_pool2d_with_indices_backward-ceil_mode-dilation-kernel_size-padding-stride-3", 957 },
  { "max_pool3d_with_indices-ceil_mode-dilation-kernel_size-padding-stride-1", 958 },
  { "max_pool3d_with_indices-dilation-kernel_size-padding-stride-1", 959 },
  { "max_pool3d_with_indices-kernel_size-padding-stride-1", 960 },
  { "max_pool3d_with_indices-kernel_size-stride-1", 961 },
  { "max_pool3d_with_indices-kernel_size-1", 962 },
  { "max_pool3d_with_indices_backward-ceil_mode-dilation-kernel_size-padding-stride-3", 963 },
  { "max_unpool2d-output_size-2", 964 },
  { "max_unpool2d_backward-output_size-3", 965 },
  { "max_unpool3d-output_size-padding-stride-2", 966 },
  { "max_unpool3d_backward-output_size-padding-stride-3", 967 },
  { "reflection_pad1d-padding-1", 968 },
  { "reflection_pad1d_backward-padding-2", 969 },
  { "reflection_pad2d-padding-1", 970 },
  { "reflection_pad2d_backward-padding-2", 971 },
  { "replication_pad1d-padding-1", 972 },
  { "replication_pad1d_backward-padding-2", 973 },
  { "replication_pad2d-padding-1", 974 },
  { "replication_pad2d_backward-padding-2", 975 },
  { "replication_pad3d-padding-1", 976 },
  { "replication_pad3d_backward-padding-2", 977 },
  { "upsample_linear1d-align_corners-output_size-1", 978 },
  { "upsample_linear1d_backward-align_corners-input_size-output_size-1", 979 },
  { "upsample_bilinear2d-align_corners-output_size-1", 980 },
  { "upsample_bilinear2d_backward-align_corners-input_size-output_size-1", 981 },
  { "upsample_bicubic2d-align_corners-output_size-1", 982 },
  { "upsample_bicubic2d_backward-align_corners-input_size-output_size-1", 983 },
  { "upsample_trilinear3d-align_corners-output_size-1", 984 },
  { "upsample_trilinear3d_backward-align_corners-input_size-output_size-1", 985 },
  { "upsample_nearest1d-output_size-1", 986 },
  { "upsample_nearest1d_backward-input_size-output_size-1", 987 },
  { "upsample_nearest2d-output_size-1", 988 },
  { "upsample_nearest2d_backward-input_size-output_size-1", 989 },
  { "upsample_nearest3d-output_size-1", 990 },
  { "upsample_nearest3d_backward-input_size-output_size-1", 991 },
  { "sigmoid_backward-2", 992 },
  { "tanh_backward-2", 993 },
  { "slow_conv_transpose2d-dilation-kernel_size-output_padding-padding-stride-3", 994 },
  { "slow_conv_transpose2d-kernel_size-output_padding-padding-stride-3", 995 },
  { "slow_conv_transpose2d-kernel_size-padding-stride-3", 996 },
  { "slow_conv_transpose2d-kernel_size-stride-3", 997 },
  { "slow_conv_transpose2d-kernel_size-3", 998 },
  { "slow_conv_transpose2d-kernel_size-2", 999 },
  { "slow_conv_transpose2d_backward-dilation-kernel_size-output_mask-output_padding-padding-stride-5", 1000 },
  { "slow_conv_transpose3d-dilation-kernel_size-output_padding-padding-stride-3", 1001 },
  { "slow_conv_transpose3d-kernel_size-output_padding-padding-stride-3", 1002 },
  { "slow_conv_transpose3d-kernel_size-padding-stride-3", 1003 },
  { "slow_conv_transpose3d-kernel_size-stride-3", 1004 },
  { "slow_conv_transpose3d-kernel_size-3", 1005 },
  { "slow_conv_transpose3d-kernel_size-2", 1006 },
  { "slow_conv_transpose3d_backward-dilation-kernel_size-output_mask-output_padding-padding-stride-5", 1007 },
  { "thnn_conv2d-kernel_size-padding-stride-3", 1008 },
  { "thnn_conv2d-kernel_size-stride-3", 1009 },
  { "thnn_conv2d-kernel_size-3", 1010 },
  { "thnn_conv2d-kernel_size-2", 1011 },
  { "thnn_conv2d_forward-kernel_size-padding-stride-3", 1012 },
  { "thnn_conv2d_backward-kernel_size-output_mask-padding-stride-5", 1013 },
  { "thnn_conv_depthwise2d-dilation-kernel_size-padding-stride-3", 1014 },
  { "thnn_conv_depthwise2d-kernel_size-padding-stride-3", 1015 },
  { "thnn_conv_depthwise2d-kernel_size-stride-3", 1016 },
  { "thnn_conv_depthwise2d-kernel_size-3", 1017 },
  { "thnn_conv_depthwise2d-kernel_size-2", 1018 },
  { "thnn_conv_depthwise2d_forward-dilation-kernel_size-padding-stride-3", 1019 },
  { "thnn_conv_depthwise2d_backward-dilation-kernel_size-output_mask-padding-stride-3", 1020 },
  { "thnn_conv3d-kernel_size-padding-stride-3", 1021 },
  { "thnn_conv3d-kernel_size-stride-3", 1022 },
  { "thnn_conv3d-kernel_size-3", 1023 },
  { "thnn_conv3d-kernel_size-2", 1024 },
  { "thnn_conv3d_forward-kernel_size-padding-stride-3", 1025 },
  { "thnn_conv3d_backward-kernel_size-output_mask-padding-stride-5", 1026 },
  { "slow_conv_dilated2d-dilation-kernel_size-padding-stride-3", 1027 },
  { "slow_conv_dilated2d-kernel_size-padding-stride-3", 1028 },
  { "slow_conv_dilated2d-kernel_size-stride-3", 1029 },
  { "slow_conv_dilated2d-kernel_size-3", 1030 },
  { "slow_conv_dilated2d-kernel_size-2", 1031 },
  { "slow_conv_dilated2d_backward-dilation-kernel_size-output_mask-padding-stride-3", 1032 },
  { "slow_conv_dilated3d-dilation-kernel_size-padding-stride-3", 1033 },
  { "slow_conv_dilated3d-kernel_size-padding-stride-3", 1034 },
  { "slow_conv_dilated3d-kernel_size-stride-3", 1035 },
  { "slow_conv_dilated3d-kernel_size-3", 1036 },
  { "slow_conv_dilated3d-kernel_size-2", 1037 },
  { "slow_conv_dilated3d_backward-dilation-kernel_size-output_mask-padding-stride-3", 1038 },
  { "col2im-dilation-kernel_size-output_size-padding-stride-1", 1039 },
  { "col2im_backward-dilation-kernel_size-padding-stride-1", 1040 },
  { "im2col-dilation-kernel_size-padding-stride-1", 1041 },
  { "im2col_backward-dilation-input_size-kernel_size-padding-stride-1", 1042 },
};

namespace caffe2 {

using at::Half; // for AT_FORALL_SCALAR_TYPES_AND2(Bool, BFloat16, ...)

template <class Context>
class ATenOp : public Operator<Context> {
 public:
  ATenOp(const OperatorDef& operator_def, Workspace* ws)
  : Operator<Context>(operator_def, ws) {
    VLOG(2) << "ATen OpDef: " << ProtoDebugString(operator_def) << "\n";
    switch(findImplementation(operator_def)) {
      case 0: { // _cast_Byte
          bool non_blocking = readAttribute<int64_t>("non_blocking");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_cast_Byte(self, non_blocking);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1: { // _cast_Byte
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_cast_Byte(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 2: { // _cast_Char
          bool non_blocking = readAttribute<int64_t>("non_blocking");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_cast_Char(self, non_blocking);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 3: { // _cast_Char
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_cast_Char(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 4: { // _cast_Double
          bool non_blocking = readAttribute<int64_t>("non_blocking");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_cast_Double(self, non_blocking);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 5: { // _cast_Double
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_cast_Double(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 6: { // _cast_Float
          bool non_blocking = readAttribute<int64_t>("non_blocking");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_cast_Float(self, non_blocking);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 7: { // _cast_Float
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_cast_Float(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 8: { // _cast_Int
          bool non_blocking = readAttribute<int64_t>("non_blocking");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_cast_Int(self, non_blocking);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 9: { // _cast_Int
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_cast_Int(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 10: { // _cast_Long
          bool non_blocking = readAttribute<int64_t>("non_blocking");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_cast_Long(self, non_blocking);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 11: { // _cast_Long
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_cast_Long(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 12: { // _cast_Short
          bool non_blocking = readAttribute<int64_t>("non_blocking");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_cast_Short(self, non_blocking);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 13: { // _cast_Short
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_cast_Short(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 14: { // _cast_Half
          bool non_blocking = readAttribute<int64_t>("non_blocking");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_cast_Half(self, non_blocking);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 15: { // _cast_Half
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_cast_Half(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 16: { // _cudnn_ctc_loss
          auto input_lengths = readIntArrayRef("input_lengths");
          auto target_lengths = readIntArrayRef("target_lengths");
          int64_t blank = readAttribute<int64_t>("blank");
          bool deterministic = readAttribute<int64_t>("deterministic");
          bool zero_infinity = readAttribute<int64_t>("zero_infinity");
          run_op = [=] {
              auto log_probs = peek(0, 2);
              auto targets = peek(1, 2);
              auto the_result = at::_cudnn_ctc_loss(log_probs, targets, input_lengths, target_lengths, blank, deterministic, zero_infinity);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 17: { // _cudnn_rnn_flatten_weight
          int64_t weight_stride0 = readAttribute<int64_t>("weight_stride0");
          int64_t input_size = readAttribute<int64_t>("input_size");
          int64_t mode = readAttribute<int64_t>("mode");
          int64_t hidden_size = readAttribute<int64_t>("hidden_size");
          int64_t num_layers = readAttribute<int64_t>("num_layers");
          bool batch_first = readAttribute<int64_t>("batch_first");
          bool bidirectional = readAttribute<int64_t>("bidirectional");
          run_op = [=] {
              auto weight_arr = peekSlice(0, InputSize() - 0, InputSize());
              auto the_result = at::_cudnn_rnn_flatten_weight(weight_arr, weight_stride0, input_size, mode, hidden_size, num_layers, batch_first, bidirectional);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 18: { // _cudnn_rnn
          int64_t weight_stride0 = readAttribute<int64_t>("weight_stride0");
          int64_t mode = readAttribute<int64_t>("mode");
          int64_t hidden_size = readAttribute<int64_t>("hidden_size");
          int64_t num_layers = readAttribute<int64_t>("num_layers");
          bool batch_first = readAttribute<int64_t>("batch_first");
          double dropout = readAttribute<float>("dropout");
          bool train = readAttribute<int64_t>("train");
          bool bidirectional = readAttribute<int64_t>("bidirectional");
          auto batch_sizes = readIntArrayRef("batch_sizes");
          run_op = [=] {
              auto input = peek(0, InputSize());
              auto weight = peekSlice(1, InputSize() - 5, InputSize());
              auto weight_buf = peek(1, 5);
              auto hx = peek(2, 5);
              auto cx = peek(3, 5);
              auto dropout_state = peek(4, 5);
              auto the_result = at::_cudnn_rnn(input, weight, weight_stride0, weight_buf, hx, cx, mode, hidden_size, num_layers, batch_first, dropout, train, bidirectional, batch_sizes, dropout_state);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
                if(OutputSize() > 3) {assignTo(Output(3),std::get<3>(the_result));}
                if(OutputSize() > 4) {assignTo(Output(4),std::get<4>(the_result));}
              return true;
          };
      } break;
      case 19: { // _debug_has_internal_overlap
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_debug_has_internal_overlap(self);
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 20: { // _fused_dropout
          double p = readAttribute<float>("p");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_fused_dropout(self, p);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 21: { // _masked_scale
          double scale = readAttribute<float>("scale");
          run_op = [=] {
              auto self = peek(0, 2);
              auto mask = peek(1, 2);
              auto the_result = at::_masked_scale(self, mask, scale);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 22: { // _reshape_from_tensor
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto shape = peek(1, 2);
              auto the_result = at::_reshape_from_tensor(self, shape);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 23: { // _shape_as_tensor
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_shape_as_tensor(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 24: { // dropout
          double p = readAttribute<float>("p");
          bool train = readAttribute<int64_t>("train");
          run_op = [=] {
              auto input = peek(0, 1);
              auto the_result = at::dropout(input, p, train);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 25: { // feature_dropout
          double p = readAttribute<float>("p");
          bool train = readAttribute<int64_t>("train");
          run_op = [=] {
              auto input = peek(0, 1);
              auto the_result = at::feature_dropout(input, p, train);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 26: { // alpha_dropout
          double p = readAttribute<float>("p");
          bool train = readAttribute<int64_t>("train");
          run_op = [=] {
              auto input = peek(0, 1);
              auto the_result = at::alpha_dropout(input, p, train);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 27: { // feature_alpha_dropout
          double p = readAttribute<float>("p");
          bool train = readAttribute<int64_t>("train");
          run_op = [=] {
              auto input = peek(0, 1);
              auto the_result = at::feature_alpha_dropout(input, p, train);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 28: { // abs
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::abs(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 29: { // acos
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::acos(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 30: { // avg_pool1d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          bool ceil_mode = readAttribute<int64_t>("ceil_mode");
          bool count_include_pad = readAttribute<int64_t>("count_include_pad");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::avg_pool1d(self, kernel_size, stride, padding, ceil_mode, count_include_pad);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 31: { // avg_pool1d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          bool ceil_mode = readAttribute<int64_t>("ceil_mode");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::avg_pool1d(self, kernel_size, stride, padding, ceil_mode);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 32: { // avg_pool1d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::avg_pool1d(self, kernel_size, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 33: { // avg_pool1d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::avg_pool1d(self, kernel_size, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 34: { // avg_pool1d
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::avg_pool1d(self, kernel_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 35: { // adaptive_avg_pool1d
          auto output_size = readIntArrayRef("output_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::adaptive_avg_pool1d(self, output_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 36: { // adaptive_max_pool1d
          auto output_size = readIntArrayRef("output_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::adaptive_max_pool1d(self, output_size);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 37: { // add
          at::Scalar alpha = readScalarAttribute("alpha");
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::add(self, other, alpha);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 38: { // add
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::add(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 39: { // add
          at::Scalar other = readScalarAttribute("other");
          at::Scalar alpha = readScalarAttribute("alpha");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::add(self, other, alpha);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 40: { // add
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::add(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 41: { // addmv
          at::Scalar beta = readScalarAttribute("beta");
          at::Scalar alpha = readScalarAttribute("alpha");
          run_op = [=] {
              auto self = peek(0, 3);
              auto mat = peek(1, 3);
              auto vec = peek(2, 3);
              auto the_result = at::addmv(self, mat, vec, beta, alpha);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 42: { // addmv
          at::Scalar beta = readScalarAttribute("beta");
          run_op = [=] {
              auto self = peek(0, 3);
              auto mat = peek(1, 3);
              auto vec = peek(2, 3);
              auto the_result = at::addmv(self, mat, vec, beta);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 43: { // addmv
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto mat = peek(1, 3);
              auto vec = peek(2, 3);
              auto the_result = at::addmv(self, mat, vec);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 44: { // addr
          at::Scalar beta = readScalarAttribute("beta");
          at::Scalar alpha = readScalarAttribute("alpha");
          run_op = [=] {
              auto self = peek(0, 3);
              auto vec1 = peek(1, 3);
              auto vec2 = peek(2, 3);
              auto the_result = at::addr(self, vec1, vec2, beta, alpha);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 45: { // addr
          at::Scalar beta = readScalarAttribute("beta");
          run_op = [=] {
              auto self = peek(0, 3);
              auto vec1 = peek(1, 3);
              auto vec2 = peek(2, 3);
              auto the_result = at::addr(self, vec1, vec2, beta);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 46: { // addr
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto vec1 = peek(1, 3);
              auto vec2 = peek(2, 3);
              auto the_result = at::addr(self, vec1, vec2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 47: { // affine_grid_generator
          auto size = readIntArrayRef("size");
          run_op = [=] {
              auto theta = peek(0, 1);
              auto the_result = at::affine_grid_generator(theta, size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 48: { // affine_grid_generator_backward
          auto size = readIntArrayRef("size");
          run_op = [=] {
              auto grad = peek(0, 1);
              auto the_result = at::affine_grid_generator_backward(grad, size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 49: { // all
          int64_t dim = readAttribute<int64_t>("dim");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::all(self, dim, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 50: { // all
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::all(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 51: { // allclose
          double rtol = readAttribute<float>("rtol");
          double atol = readAttribute<float>("atol");
          bool equal_nan = readAttribute<int64_t>("equal_nan");
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::allclose(self, other, rtol, atol, equal_nan);
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 52: { // allclose
          double rtol = readAttribute<float>("rtol");
          double atol = readAttribute<float>("atol");
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::allclose(self, other, rtol, atol);
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 53: { // allclose
          double rtol = readAttribute<float>("rtol");
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::allclose(self, other, rtol);
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 54: { // allclose
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::allclose(self, other);
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 55: { // any
          int64_t dim = readAttribute<int64_t>("dim");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::any(self, dim, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 56: { // any
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::any(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 57: { // _dim_arange
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto like = peek(0, 1);
              auto the_result = at::_dim_arange(like, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 58: { // argmax
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::argmax(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 59: { // argmin
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::argmin(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 60: { // as_strided
          auto size = readIntArrayRef("size");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::as_strided(self, size, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 61: { // asin
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::asin(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 62: { // atan
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::atan(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 63: { // baddbmm
          at::Scalar beta = readScalarAttribute("beta");
          at::Scalar alpha = readScalarAttribute("alpha");
          run_op = [=] {
              auto self = peek(0, 3);
              auto batch1 = peek(1, 3);
              auto batch2 = peek(2, 3);
              auto the_result = at::baddbmm(self, batch1, batch2, beta, alpha);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 64: { // baddbmm
          at::Scalar beta = readScalarAttribute("beta");
          run_op = [=] {
              auto self = peek(0, 3);
              auto batch1 = peek(1, 3);
              auto batch2 = peek(2, 3);
              auto the_result = at::baddbmm(self, batch1, batch2, beta);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 65: { // baddbmm
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto batch1 = peek(1, 3);
              auto batch2 = peek(2, 3);
              auto the_result = at::baddbmm(self, batch1, batch2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 66: { // batch_norm
          bool training = readAttribute<int64_t>("training");
          double momentum = readAttribute<float>("momentum");
          double eps = readAttribute<float>("eps");
          bool cudnn_enabled = readAttribute<int64_t>("cudnn_enabled");
          run_op = [=] {
              auto input = peek(0, 5);
              auto weight = peek(1, 5);
              auto bias = peek(2, 5);
              auto running_mean = peek(3, 5);
              auto running_var = peek(4, 5);
              auto the_result = at::batch_norm(input, weight, bias, running_mean, running_var, training, momentum, eps, cudnn_enabled);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 67: { // _batch_norm_impl_index
          bool training = readAttribute<int64_t>("training");
          double momentum = readAttribute<float>("momentum");
          double eps = readAttribute<float>("eps");
          bool cudnn_enabled = readAttribute<int64_t>("cudnn_enabled");
          run_op = [=] {
              auto input = peek(0, 5);
              auto weight = peek(1, 5);
              auto bias = peek(2, 5);
              auto running_mean = peek(3, 5);
              auto running_var = peek(4, 5);
              auto the_result = at::_batch_norm_impl_index(input, weight, bias, running_mean, running_var, training, momentum, eps, cudnn_enabled);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
                if(OutputSize() > 3) {assignToValue<int64_t>(Output(3),std::get<3>(the_result));}
              return true;
          };
      } break;
      case 68: { // _batch_norm_impl_index_backward
          int64_t impl_index = readAttribute<int64_t>("impl_index");
          bool train = readAttribute<int64_t>("train");
          double eps = readAttribute<float>("eps");
          auto output_mask = readBoolMask<3>("output_mask");
          run_op = [=] {
              auto input = peek(0, 7);
              auto grad_output = peek(1, 7);
              auto weight = peek(2, 7);
              auto running_mean = peek(3, 7);
              auto running_var = peek(4, 7);
              auto save_mean = peek(5, 7);
              auto save_var_transform = peek(6, 7);
              auto the_result = at::_batch_norm_impl_index_backward(impl_index, input, grad_output, weight, running_mean, running_var, save_mean, save_var_transform, train, eps, output_mask);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 69: { // bernoulli
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::bernoulli(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 70: { // bernoulli
          double p = readAttribute<float>("p");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::bernoulli(self, p);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 71: { // bilinear
      
          run_op = [=] {
              auto input1 = peek(0, 4);
              auto input2 = peek(1, 4);
              auto weight = peek(2, 4);
              auto bias = peek(3, 4);
              auto the_result = at::bilinear(input1, input2, weight, bias);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 72: { // binary_cross_entropy_with_logits
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto self = peek(0, 4);
              auto target = peek(1, 4);
              auto weight = peek(2, 4);
              auto pos_weight = peek(3, 4);
              auto the_result = at::binary_cross_entropy_with_logits(self, target, weight, pos_weight, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 73: { // binary_cross_entropy_with_logits
      
          run_op = [=] {
              auto self = peek(0, 4);
              auto target = peek(1, 4);
              auto weight = peek(2, 4);
              auto pos_weight = peek(3, 4);
              auto the_result = at::binary_cross_entropy_with_logits(self, target, weight, pos_weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 74: { // binary_cross_entropy_with_logits
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto target = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::binary_cross_entropy_with_logits(self, target, weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 75: { // binary_cross_entropy_with_logits
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::binary_cross_entropy_with_logits(self, target);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 76: { // binary_cross_entropy_with_logits_backward
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto grad_output = peek(0, 5);
              auto self = peek(1, 5);
              auto target = peek(2, 5);
              auto weight = peek(3, 5);
              auto pos_weight = peek(4, 5);
              auto the_result = at::binary_cross_entropy_with_logits_backward(grad_output, self, target, weight, pos_weight, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 77: { // binary_cross_entropy_with_logits_backward
      
          run_op = [=] {
              auto grad_output = peek(0, 5);
              auto self = peek(1, 5);
              auto target = peek(2, 5);
              auto weight = peek(3, 5);
              auto pos_weight = peek(4, 5);
              auto the_result = at::binary_cross_entropy_with_logits_backward(grad_output, self, target, weight, pos_weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 78: { // binary_cross_entropy_with_logits_backward
      
          run_op = [=] {
              auto grad_output = peek(0, 4);
              auto self = peek(1, 4);
              auto target = peek(2, 4);
              auto weight = peek(3, 4);
              auto the_result = at::binary_cross_entropy_with_logits_backward(grad_output, self, target, weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 79: { // binary_cross_entropy_with_logits_backward
      
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto target = peek(2, 3);
              auto the_result = at::binary_cross_entropy_with_logits_backward(grad_output, self, target);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 80: { // bincount
          int64_t minlength = readAttribute<int64_t>("minlength");
          run_op = [=] {
              auto self = peek(0, 2);
              auto weights = peek(1, 2);
              auto the_result = at::bincount(self, weights, minlength);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 81: { // bincount
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto weights = peek(1, 2);
              auto the_result = at::bincount(self, weights);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 82: { // bincount
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::bincount(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 83: { // bitwise_not
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::bitwise_not(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 84: { // logical_not
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::logical_not(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 85: { // logical_xor
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::logical_xor(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 86: { // bmm
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto mat2 = peek(1, 2);
              auto the_result = at::bmm(self, mat2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 87: { // broadcast_tensors
      
          run_op = [=] {
              auto tensors = peekSlice(0, InputSize() - 0, InputSize());
              auto the_result = at::broadcast_tensors(tensors);
                if(OutputSize() > 0) {assignListStartingAt(0, the_result);}
              return true;
          };
      } break;
      case 88: { // cat
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto tensors = peekSlice(0, InputSize() - 0, InputSize());
              auto the_result = at::cat(tensors, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 89: { // cat
      
          run_op = [=] {
              auto tensors = peekSlice(0, InputSize() - 0, InputSize());
              auto the_result = at::cat(tensors);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 90: { // ceil
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::ceil(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 91: { // chain_matmul
      
          run_op = [=] {
              auto matrices = peekSlice(0, InputSize() - 0, InputSize());
              auto the_result = at::chain_matmul(matrices);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 92: { // chunk
          int64_t chunks = readAttribute<int64_t>("chunks");
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::chunk(self, chunks, dim);
                if(OutputSize() > 0) {assignListStartingAt(0, the_result);}
              return true;
          };
      } break;
      case 93: { // chunk
          int64_t chunks = readAttribute<int64_t>("chunks");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::chunk(self, chunks);
                if(OutputSize() > 0) {assignListStartingAt(0, the_result);}
              return true;
          };
      } break;
      case 94: { // clamp
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::clamp(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 95: { // clamp_max
          at::Scalar max = readScalarAttribute("max");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::clamp_max(self, max);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 96: { // clamp_min
          at::Scalar min = readScalarAttribute("min");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::clamp_min(self, min);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 97: { // cudnn_is_acceptable
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::cudnn_is_acceptable(self);
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 98: { // constant_pad_nd
          auto pad = readIntArrayRef("pad");
          at::Scalar value = readScalarAttribute("value");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::constant_pad_nd(self, pad, value);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 99: { // constant_pad_nd
          auto pad = readIntArrayRef("pad");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::constant_pad_nd(self, pad);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 100: { // contiguous
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self.contiguous();
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 101: { // convolution
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          bool transposed = readAttribute<int64_t>("transposed");
          auto output_padding = readIntArrayRef("output_padding");
          int64_t groups = readAttribute<int64_t>("groups");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::convolution(input, weight, bias, stride, padding, dilation, transposed, output_padding, groups);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 102: { // _convolution
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          bool transposed = readAttribute<int64_t>("transposed");
          auto output_padding = readIntArrayRef("output_padding");
          int64_t groups = readAttribute<int64_t>("groups");
          bool benchmark = readAttribute<int64_t>("benchmark");
          bool deterministic = readAttribute<int64_t>("deterministic");
          bool cudnn_enabled = readAttribute<int64_t>("cudnn_enabled");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::_convolution(input, weight, bias, stride, padding, dilation, transposed, output_padding, groups, benchmark, deterministic, cudnn_enabled);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 103: { // _convolution_nogroup
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          bool transposed = readAttribute<int64_t>("transposed");
          auto output_padding = readIntArrayRef("output_padding");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::_convolution_nogroup(input, weight, bias, stride, padding, dilation, transposed, output_padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 104: { // _convolution_double_backward
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          bool transposed = readAttribute<int64_t>("transposed");
          auto output_padding = readIntArrayRef("output_padding");
          int64_t groups = readAttribute<int64_t>("groups");
          bool benchmark = readAttribute<int64_t>("benchmark");
          bool deterministic = readAttribute<int64_t>("deterministic");
          bool cudnn_enabled = readAttribute<int64_t>("cudnn_enabled");
          auto output_mask = readBoolMask<3>("output_mask");
          run_op = [=] {
              auto ggI = peek(0, 6);
              auto ggW = peek(1, 6);
              auto ggb = peek(2, 6);
              auto gO = peek(3, 6);
              auto weight = peek(4, 6);
              auto self = peek(5, 6);
              auto the_result = at::_convolution_double_backward(ggI, ggW, ggb, gO, weight, self, stride, padding, dilation, transposed, output_padding, groups, benchmark, deterministic, cudnn_enabled, output_mask);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 105: { // conv1d
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv1d(input, weight, bias, stride, padding, dilation, groups);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 106: { // conv1d
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv1d(input, weight, bias, stride, padding, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 107: { // conv1d
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv1d(input, weight, bias, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 108: { // conv1d
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv1d(input, weight, bias, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 109: { // conv1d
      
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv1d(input, weight, bias);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 110: { // conv1d
      
          run_op = [=] {
              auto input = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::conv1d(input, weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 111: { // conv2d
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv2d(input, weight, bias, stride, padding, dilation, groups);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 112: { // conv2d
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv2d(input, weight, bias, stride, padding, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 113: { // conv2d
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv2d(input, weight, bias, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 114: { // conv2d
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv2d(input, weight, bias, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 115: { // conv2d
      
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv2d(input, weight, bias);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 116: { // conv2d
      
          run_op = [=] {
              auto input = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::conv2d(input, weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 117: { // conv3d
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv3d(input, weight, bias, stride, padding, dilation, groups);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 118: { // conv3d
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv3d(input, weight, bias, stride, padding, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 119: { // conv3d
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv3d(input, weight, bias, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 120: { // conv3d
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv3d(input, weight, bias, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 121: { // conv3d
      
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv3d(input, weight, bias);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 122: { // conv3d
      
          run_op = [=] {
              auto input = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::conv3d(input, weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 123: { // conv_tbc
          int64_t pad = readAttribute<int64_t>("pad");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv_tbc(self, weight, bias, pad);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 124: { // conv_tbc
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv_tbc(self, weight, bias);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 125: { // conv_tbc_backward
          int64_t pad = readAttribute<int64_t>("pad");
          run_op = [=] {
              auto self = peek(0, 4);
              auto input = peek(1, 4);
              auto weight = peek(2, 4);
              auto bias = peek(3, 4);
              auto the_result = at::conv_tbc_backward(self, input, weight, bias, pad);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 126: { // conv_transpose1d
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto output_padding = readIntArrayRef("output_padding");
          int64_t groups = readAttribute<int64_t>("groups");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv_transpose1d(input, weight, bias, stride, padding, output_padding, groups, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 127: { // conv_transpose1d
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto output_padding = readIntArrayRef("output_padding");
          int64_t groups = readAttribute<int64_t>("groups");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv_transpose1d(input, weight, bias, stride, padding, output_padding, groups);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 128: { // conv_transpose1d
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto output_padding = readIntArrayRef("output_padding");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv_transpose1d(input, weight, bias, stride, padding, output_padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 129: { // conv_transpose1d
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv_transpose1d(input, weight, bias, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 130: { // conv_transpose1d
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv_transpose1d(input, weight, bias, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 131: { // conv_transpose1d
      
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv_transpose1d(input, weight, bias);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 132: { // conv_transpose1d
      
          run_op = [=] {
              auto input = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::conv_transpose1d(input, weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 133: { // conv_transpose2d
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto output_padding = readIntArrayRef("output_padding");
          int64_t groups = readAttribute<int64_t>("groups");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv_transpose2d(input, weight, bias, stride, padding, output_padding, groups, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 134: { // conv_transpose2d
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto output_padding = readIntArrayRef("output_padding");
          int64_t groups = readAttribute<int64_t>("groups");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv_transpose2d(input, weight, bias, stride, padding, output_padding, groups);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 135: { // conv_transpose2d
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto output_padding = readIntArrayRef("output_padding");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv_transpose2d(input, weight, bias, stride, padding, output_padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 136: { // conv_transpose2d
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv_transpose2d(input, weight, bias, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 137: { // conv_transpose2d
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv_transpose2d(input, weight, bias, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 138: { // conv_transpose2d
      
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv_transpose2d(input, weight, bias);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 139: { // conv_transpose2d
      
          run_op = [=] {
              auto input = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::conv_transpose2d(input, weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 140: { // conv_transpose3d
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto output_padding = readIntArrayRef("output_padding");
          int64_t groups = readAttribute<int64_t>("groups");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv_transpose3d(input, weight, bias, stride, padding, output_padding, groups, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 141: { // conv_transpose3d
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto output_padding = readIntArrayRef("output_padding");
          int64_t groups = readAttribute<int64_t>("groups");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv_transpose3d(input, weight, bias, stride, padding, output_padding, groups);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 142: { // conv_transpose3d
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto output_padding = readIntArrayRef("output_padding");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv_transpose3d(input, weight, bias, stride, padding, output_padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 143: { // conv_transpose3d
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv_transpose3d(input, weight, bias, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 144: { // conv_transpose3d
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv_transpose3d(input, weight, bias, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 145: { // conv_transpose3d
      
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv_transpose3d(input, weight, bias);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 146: { // conv_transpose3d
      
          run_op = [=] {
              auto input = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::conv_transpose3d(input, weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 147: { // _copy_from
          bool non_blocking = readAttribute<int64_t>("non_blocking");
          run_op = [=] {
              auto self = peek(0, 2);
              auto dst = peek(1, 2);
              auto the_result = at::_copy_from(self, dst, non_blocking);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 148: { // _copy_from
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto dst = peek(1, 2);
              auto the_result = at::_copy_from(self, dst);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 149: { // cos
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::cos(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 150: { // cosh
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::cosh(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 151: { // cosine_embedding_loss
          double margin = readAttribute<float>("margin");
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto input1 = peek(0, 3);
              auto input2 = peek(1, 3);
              auto target = peek(2, 3);
              auto the_result = at::cosine_embedding_loss(input1, input2, target, margin, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 152: { // cosine_embedding_loss
          double margin = readAttribute<float>("margin");
          run_op = [=] {
              auto input1 = peek(0, 3);
              auto input2 = peek(1, 3);
              auto target = peek(2, 3);
              auto the_result = at::cosine_embedding_loss(input1, input2, target, margin);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 153: { // cosine_embedding_loss
      
          run_op = [=] {
              auto input1 = peek(0, 3);
              auto input2 = peek(1, 3);
              auto target = peek(2, 3);
              auto the_result = at::cosine_embedding_loss(input1, input2, target);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 154: { // cudnn_affine_grid_generator
          int64_t N = readAttribute<int64_t>("N");
          int64_t C = readAttribute<int64_t>("C");
          int64_t H = readAttribute<int64_t>("H");
          int64_t W = readAttribute<int64_t>("W");
          run_op = [=] {
              auto theta = peek(0, 1);
              auto the_result = at::cudnn_affine_grid_generator(theta, N, C, H, W);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 155: { // cudnn_affine_grid_generator_backward
          int64_t N = readAttribute<int64_t>("N");
          int64_t C = readAttribute<int64_t>("C");
          int64_t H = readAttribute<int64_t>("H");
          int64_t W = readAttribute<int64_t>("W");
          run_op = [=] {
              auto grad = peek(0, 1);
              auto the_result = at::cudnn_affine_grid_generator_backward(grad, N, C, H, W);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 156: { // cudnn_batch_norm
          bool training = readAttribute<int64_t>("training");
          double exponential_average_factor = readAttribute<float>("exponential_average_factor");
          double epsilon = readAttribute<float>("epsilon");
          run_op = [=] {
              auto input = peek(0, 5);
              auto weight = peek(1, 5);
              auto bias = peek(2, 5);
              auto running_mean = peek(3, 5);
              auto running_var = peek(4, 5);
              auto the_result = at::cudnn_batch_norm(input, weight, bias, running_mean, running_var, training, exponential_average_factor, epsilon);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 157: { // cudnn_batch_norm_backward
          double epsilon = readAttribute<float>("epsilon");
          run_op = [=] {
              auto input = peek(0, 7);
              auto grad_output = peek(1, 7);
              auto weight = peek(2, 7);
              auto running_mean = peek(3, 7);
              auto running_var = peek(4, 7);
              auto save_mean = peek(5, 7);
              auto save_var = peek(6, 7);
              auto the_result = at::cudnn_batch_norm_backward(input, grad_output, weight, running_mean, running_var, save_mean, save_var, epsilon);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 158: { // cudnn_convolution
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          bool benchmark = readAttribute<int64_t>("benchmark");
          bool deterministic = readAttribute<int64_t>("deterministic");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::cudnn_convolution(self, weight, bias, padding, stride, dilation, groups, benchmark, deterministic);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 159: { // cudnn_convolution_backward_input
          auto self_size = readIntArrayRef("self_size");
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          bool benchmark = readAttribute<int64_t>("benchmark");
          bool deterministic = readAttribute<int64_t>("deterministic");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::cudnn_convolution_backward_input(self_size, grad_output, weight, padding, stride, dilation, groups, benchmark, deterministic);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 160: { // cudnn_convolution_backward
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          bool benchmark = readAttribute<int64_t>("benchmark");
          bool deterministic = readAttribute<int64_t>("deterministic");
          auto output_mask = readBoolMask<3>("output_mask");
          run_op = [=] {
              auto self = peek(0, 3);
              auto grad_output = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::cudnn_convolution_backward(self, grad_output, weight, padding, stride, dilation, groups, benchmark, deterministic, output_mask);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 161: { // cudnn_convolution_backward_bias
      
          run_op = [=] {
              auto grad_output = peek(0, 1);
              auto the_result = at::cudnn_convolution_backward_bias(grad_output);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 162: { // cudnn_convolution_backward_weight
          auto weight_size = readIntArrayRef("weight_size");
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          bool benchmark = readAttribute<int64_t>("benchmark");
          bool deterministic = readAttribute<int64_t>("deterministic");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::cudnn_convolution_backward_weight(weight_size, grad_output, self, padding, stride, dilation, groups, benchmark, deterministic);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 163: { // cudnn_convolution_transpose
          auto padding = readIntArrayRef("padding");
          auto output_padding = readIntArrayRef("output_padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          bool benchmark = readAttribute<int64_t>("benchmark");
          bool deterministic = readAttribute<int64_t>("deterministic");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::cudnn_convolution_transpose(self, weight, bias, padding, output_padding, stride, dilation, groups, benchmark, deterministic);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 164: { // cudnn_convolution_transpose_backward
          auto padding = readIntArrayRef("padding");
          auto output_padding = readIntArrayRef("output_padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          bool benchmark = readAttribute<int64_t>("benchmark");
          bool deterministic = readAttribute<int64_t>("deterministic");
          auto output_mask = readBoolMask<3>("output_mask");
          run_op = [=] {
              auto self = peek(0, 3);
              auto grad_output = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::cudnn_convolution_transpose_backward(self, grad_output, weight, padding, output_padding, stride, dilation, groups, benchmark, deterministic, output_mask);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 165: { // cudnn_convolution_transpose_backward_bias
      
          run_op = [=] {
              auto grad_output = peek(0, 1);
              auto the_result = at::cudnn_convolution_transpose_backward_bias(grad_output);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 166: { // cudnn_convolution_transpose_backward_input
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          bool benchmark = readAttribute<int64_t>("benchmark");
          bool deterministic = readAttribute<int64_t>("deterministic");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::cudnn_convolution_transpose_backward_input(grad_output, weight, padding, stride, dilation, groups, benchmark, deterministic);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 167: { // cudnn_convolution_transpose_backward_weight
          auto weight_size = readIntArrayRef("weight_size");
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          bool benchmark = readAttribute<int64_t>("benchmark");
          bool deterministic = readAttribute<int64_t>("deterministic");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::cudnn_convolution_transpose_backward_weight(weight_size, grad_output, self, padding, stride, dilation, groups, benchmark, deterministic);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 168: { // cudnn_grid_sampler
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto grid = peek(1, 2);
              auto the_result = at::cudnn_grid_sampler(self, grid);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 169: { // cudnn_grid_sampler_backward
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto grid = peek(1, 3);
              auto grad_output = peek(2, 3);
              auto the_result = at::cudnn_grid_sampler_backward(self, grid, grad_output);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 170: { // cumsum
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::cumsum(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 171: { // cumprod
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::cumprod(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 172: { // ctc_loss
          auto input_lengths = readIntArrayRef("input_lengths");
          auto target_lengths = readIntArrayRef("target_lengths");
          int64_t blank = readAttribute<int64_t>("blank");
          int64_t reduction = readAttribute<int64_t>("reduction");
          bool zero_infinity = readAttribute<int64_t>("zero_infinity");
          run_op = [=] {
              auto log_probs = peek(0, 2);
              auto targets = peek(1, 2);
              auto the_result = at::ctc_loss(log_probs, targets, input_lengths, target_lengths, blank, reduction, zero_infinity);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 173: { // ctc_loss
          auto input_lengths = readIntArrayRef("input_lengths");
          auto target_lengths = readIntArrayRef("target_lengths");
          int64_t blank = readAttribute<int64_t>("blank");
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto log_probs = peek(0, 2);
              auto targets = peek(1, 2);
              auto the_result = at::ctc_loss(log_probs, targets, input_lengths, target_lengths, blank, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 174: { // ctc_loss
          auto input_lengths = readIntArrayRef("input_lengths");
          auto target_lengths = readIntArrayRef("target_lengths");
          int64_t blank = readAttribute<int64_t>("blank");
          run_op = [=] {
              auto log_probs = peek(0, 2);
              auto targets = peek(1, 2);
              auto the_result = at::ctc_loss(log_probs, targets, input_lengths, target_lengths, blank);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 175: { // ctc_loss
          auto input_lengths = readIntArrayRef("input_lengths");
          auto target_lengths = readIntArrayRef("target_lengths");
          run_op = [=] {
              auto log_probs = peek(0, 2);
              auto targets = peek(1, 2);
              auto the_result = at::ctc_loss(log_probs, targets, input_lengths, target_lengths);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 176: { // ctc_loss
          int64_t blank = readAttribute<int64_t>("blank");
          int64_t reduction = readAttribute<int64_t>("reduction");
          bool zero_infinity = readAttribute<int64_t>("zero_infinity");
          run_op = [=] {
              auto log_probs = peek(0, 4);
              auto targets = peek(1, 4);
              auto input_lengths = peek(2, 4);
              auto target_lengths = peek(3, 4);
              auto the_result = at::ctc_loss(log_probs, targets, input_lengths, target_lengths, blank, reduction, zero_infinity);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 177: { // ctc_loss
          int64_t blank = readAttribute<int64_t>("blank");
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto log_probs = peek(0, 4);
              auto targets = peek(1, 4);
              auto input_lengths = peek(2, 4);
              auto target_lengths = peek(3, 4);
              auto the_result = at::ctc_loss(log_probs, targets, input_lengths, target_lengths, blank, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 178: { // ctc_loss
          int64_t blank = readAttribute<int64_t>("blank");
          run_op = [=] {
              auto log_probs = peek(0, 4);
              auto targets = peek(1, 4);
              auto input_lengths = peek(2, 4);
              auto target_lengths = peek(3, 4);
              auto the_result = at::ctc_loss(log_probs, targets, input_lengths, target_lengths, blank);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 179: { // ctc_loss
      
          run_op = [=] {
              auto log_probs = peek(0, 4);
              auto targets = peek(1, 4);
              auto input_lengths = peek(2, 4);
              auto target_lengths = peek(3, 4);
              auto the_result = at::ctc_loss(log_probs, targets, input_lengths, target_lengths);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 180: { // _ctc_loss
          auto input_lengths = readIntArrayRef("input_lengths");
          auto target_lengths = readIntArrayRef("target_lengths");
          int64_t blank = readAttribute<int64_t>("blank");
          bool zero_infinity = readAttribute<int64_t>("zero_infinity");
          run_op = [=] {
              auto log_probs = peek(0, 2);
              auto targets = peek(1, 2);
              auto the_result = at::_ctc_loss(log_probs, targets, input_lengths, target_lengths, blank, zero_infinity);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 181: { // _ctc_loss
          auto input_lengths = readIntArrayRef("input_lengths");
          auto target_lengths = readIntArrayRef("target_lengths");
          int64_t blank = readAttribute<int64_t>("blank");
          run_op = [=] {
              auto log_probs = peek(0, 2);
              auto targets = peek(1, 2);
              auto the_result = at::_ctc_loss(log_probs, targets, input_lengths, target_lengths, blank);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 182: { // _ctc_loss
          auto input_lengths = readIntArrayRef("input_lengths");
          auto target_lengths = readIntArrayRef("target_lengths");
          run_op = [=] {
              auto log_probs = peek(0, 2);
              auto targets = peek(1, 2);
              auto the_result = at::_ctc_loss(log_probs, targets, input_lengths, target_lengths);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 183: { // _ctc_loss_backward
          auto input_lengths = readIntArrayRef("input_lengths");
          auto target_lengths = readIntArrayRef("target_lengths");
          int64_t blank = readAttribute<int64_t>("blank");
          bool zero_infinity = readAttribute<int64_t>("zero_infinity");
          run_op = [=] {
              auto grad = peek(0, 5);
              auto log_probs = peek(1, 5);
              auto targets = peek(2, 5);
              auto neg_log_likelihood = peek(3, 5);
              auto log_alpha = peek(4, 5);
              auto the_result = at::_ctc_loss_backward(grad, log_probs, targets, input_lengths, target_lengths, neg_log_likelihood, log_alpha, blank, zero_infinity);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 184: { // _ctc_loss_backward
          auto input_lengths = readIntArrayRef("input_lengths");
          auto target_lengths = readIntArrayRef("target_lengths");
          int64_t blank = readAttribute<int64_t>("blank");
          run_op = [=] {
              auto grad = peek(0, 5);
              auto log_probs = peek(1, 5);
              auto targets = peek(2, 5);
              auto neg_log_likelihood = peek(3, 5);
              auto log_alpha = peek(4, 5);
              auto the_result = at::_ctc_loss_backward(grad, log_probs, targets, input_lengths, target_lengths, neg_log_likelihood, log_alpha, blank);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 185: { // det
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::det(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 186: { // diag_embed
          int64_t offset = readAttribute<int64_t>("offset");
          int64_t dim1 = readAttribute<int64_t>("dim1");
          int64_t dim2 = readAttribute<int64_t>("dim2");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::diag_embed(self, offset, dim1, dim2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 187: { // diag_embed
          int64_t offset = readAttribute<int64_t>("offset");
          int64_t dim1 = readAttribute<int64_t>("dim1");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::diag_embed(self, offset, dim1);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 188: { // diag_embed
          int64_t offset = readAttribute<int64_t>("offset");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::diag_embed(self, offset);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 189: { // diag_embed
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::diag_embed(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 190: { // diagflat
          int64_t offset = readAttribute<int64_t>("offset");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::diagflat(self, offset);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 191: { // diagflat
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::diagflat(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 192: { // diagonal
          int64_t offset = readAttribute<int64_t>("offset");
          int64_t dim1 = readAttribute<int64_t>("dim1");
          int64_t dim2 = readAttribute<int64_t>("dim2");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::diagonal(self, offset, dim1, dim2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 193: { // diagonal
          int64_t offset = readAttribute<int64_t>("offset");
          int64_t dim1 = readAttribute<int64_t>("dim1");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::diagonal(self, offset, dim1);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 194: { // diagonal
          int64_t offset = readAttribute<int64_t>("offset");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::diagonal(self, offset);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 195: { // diagonal
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::diagonal(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 196: { // div
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::div(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 197: { // div
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::div(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 198: { // dot
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto tensor = peek(1, 2);
              auto the_result = at::dot(self, tensor);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 199: { // embedding
          int64_t padding_idx = readAttribute<int64_t>("padding_idx");
          bool scale_grad_by_freq = readAttribute<int64_t>("scale_grad_by_freq");
          bool sparse = readAttribute<int64_t>("sparse");
          run_op = [=] {
              auto weight = peek(0, 2);
              auto indices = peek(1, 2);
              auto the_result = at::embedding(weight, indices, padding_idx, scale_grad_by_freq, sparse);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 200: { // embedding
          int64_t padding_idx = readAttribute<int64_t>("padding_idx");
          bool scale_grad_by_freq = readAttribute<int64_t>("scale_grad_by_freq");
          run_op = [=] {
              auto weight = peek(0, 2);
              auto indices = peek(1, 2);
              auto the_result = at::embedding(weight, indices, padding_idx, scale_grad_by_freq);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 201: { // embedding
          int64_t padding_idx = readAttribute<int64_t>("padding_idx");
          run_op = [=] {
              auto weight = peek(0, 2);
              auto indices = peek(1, 2);
              auto the_result = at::embedding(weight, indices, padding_idx);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 202: { // embedding
      
          run_op = [=] {
              auto weight = peek(0, 2);
              auto indices = peek(1, 2);
              auto the_result = at::embedding(weight, indices);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 203: { // embedding_backward
          int64_t num_weights = readAttribute<int64_t>("num_weights");
          int64_t padding_idx = readAttribute<int64_t>("padding_idx");
          bool scale_grad_by_freq = readAttribute<int64_t>("scale_grad_by_freq");
          bool sparse = readAttribute<int64_t>("sparse");
          run_op = [=] {
              auto grad = peek(0, 2);
              auto indices = peek(1, 2);
              auto the_result = at::embedding_backward(grad, indices, num_weights, padding_idx, scale_grad_by_freq, sparse);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 204: { // embedding_dense_backward
          int64_t num_weights = readAttribute<int64_t>("num_weights");
          int64_t padding_idx = readAttribute<int64_t>("padding_idx");
          bool scale_grad_by_freq = readAttribute<int64_t>("scale_grad_by_freq");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto indices = peek(1, 2);
              auto the_result = at::embedding_dense_backward(grad_output, indices, num_weights, padding_idx, scale_grad_by_freq);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 205: { // embedding_sparse_backward
          int64_t num_weights = readAttribute<int64_t>("num_weights");
          int64_t padding_idx = readAttribute<int64_t>("padding_idx");
          bool scale_grad_by_freq = readAttribute<int64_t>("scale_grad_by_freq");
          run_op = [=] {
              auto grad = peek(0, 2);
              auto indices = peek(1, 2);
              auto the_result = at::embedding_sparse_backward(grad, indices, num_weights, padding_idx, scale_grad_by_freq);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 206: { // embedding_bag
          bool scale_grad_by_freq = readAttribute<int64_t>("scale_grad_by_freq");
          int64_t mode = readAttribute<int64_t>("mode");
          bool sparse = readAttribute<int64_t>("sparse");
          run_op = [=] {
              auto weight = peek(0, 4);
              auto indices = peek(1, 4);
              auto offsets = peek(2, 4);
              auto per_sample_weights = peek(3, 4);
              auto the_result = at::embedding_bag(weight, indices, offsets, scale_grad_by_freq, mode, sparse, per_sample_weights);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
                if(OutputSize() > 3) {assignTo(Output(3),std::get<3>(the_result));}
              return true;
          };
      } break;
      case 207: { // embedding_bag
          bool scale_grad_by_freq = readAttribute<int64_t>("scale_grad_by_freq");
          int64_t mode = readAttribute<int64_t>("mode");
          bool sparse = readAttribute<int64_t>("sparse");
          run_op = [=] {
              auto weight = peek(0, 3);
              auto indices = peek(1, 3);
              auto offsets = peek(2, 3);
              auto the_result = at::embedding_bag(weight, indices, offsets, scale_grad_by_freq, mode, sparse);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
                if(OutputSize() > 3) {assignTo(Output(3),std::get<3>(the_result));}
              return true;
          };
      } break;
      case 208: { // embedding_bag
          bool scale_grad_by_freq = readAttribute<int64_t>("scale_grad_by_freq");
          int64_t mode = readAttribute<int64_t>("mode");
          run_op = [=] {
              auto weight = peek(0, 3);
              auto indices = peek(1, 3);
              auto offsets = peek(2, 3);
              auto the_result = at::embedding_bag(weight, indices, offsets, scale_grad_by_freq, mode);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
                if(OutputSize() > 3) {assignTo(Output(3),std::get<3>(the_result));}
              return true;
          };
      } break;
      case 209: { // embedding_bag
          bool scale_grad_by_freq = readAttribute<int64_t>("scale_grad_by_freq");
          run_op = [=] {
              auto weight = peek(0, 3);
              auto indices = peek(1, 3);
              auto offsets = peek(2, 3);
              auto the_result = at::embedding_bag(weight, indices, offsets, scale_grad_by_freq);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
                if(OutputSize() > 3) {assignTo(Output(3),std::get<3>(the_result));}
              return true;
          };
      } break;
      case 210: { // embedding_bag
      
          run_op = [=] {
              auto weight = peek(0, 3);
              auto indices = peek(1, 3);
              auto offsets = peek(2, 3);
              auto the_result = at::embedding_bag(weight, indices, offsets);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
                if(OutputSize() > 3) {assignTo(Output(3),std::get<3>(the_result));}
              return true;
          };
      } break;
      case 211: { // _embedding_bag
          bool scale_grad_by_freq = readAttribute<int64_t>("scale_grad_by_freq");
          int64_t mode = readAttribute<int64_t>("mode");
          bool sparse = readAttribute<int64_t>("sparse");
          run_op = [=] {
              auto weight = peek(0, 4);
              auto indices = peek(1, 4);
              auto offsets = peek(2, 4);
              auto per_sample_weights = peek(3, 4);
              auto the_result = at::_embedding_bag(weight, indices, offsets, scale_grad_by_freq, mode, sparse, per_sample_weights);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
                if(OutputSize() > 3) {assignTo(Output(3),std::get<3>(the_result));}
              return true;
          };
      } break;
      case 212: { // _embedding_bag
          bool scale_grad_by_freq = readAttribute<int64_t>("scale_grad_by_freq");
          int64_t mode = readAttribute<int64_t>("mode");
          bool sparse = readAttribute<int64_t>("sparse");
          run_op = [=] {
              auto weight = peek(0, 3);
              auto indices = peek(1, 3);
              auto offsets = peek(2, 3);
              auto the_result = at::_embedding_bag(weight, indices, offsets, scale_grad_by_freq, mode, sparse);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
                if(OutputSize() > 3) {assignTo(Output(3),std::get<3>(the_result));}
              return true;
          };
      } break;
      case 213: { // _embedding_bag
          bool scale_grad_by_freq = readAttribute<int64_t>("scale_grad_by_freq");
          int64_t mode = readAttribute<int64_t>("mode");
          run_op = [=] {
              auto weight = peek(0, 3);
              auto indices = peek(1, 3);
              auto offsets = peek(2, 3);
              auto the_result = at::_embedding_bag(weight, indices, offsets, scale_grad_by_freq, mode);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
                if(OutputSize() > 3) {assignTo(Output(3),std::get<3>(the_result));}
              return true;
          };
      } break;
      case 214: { // _embedding_bag
          bool scale_grad_by_freq = readAttribute<int64_t>("scale_grad_by_freq");
          run_op = [=] {
              auto weight = peek(0, 3);
              auto indices = peek(1, 3);
              auto offsets = peek(2, 3);
              auto the_result = at::_embedding_bag(weight, indices, offsets, scale_grad_by_freq);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
                if(OutputSize() > 3) {assignTo(Output(3),std::get<3>(the_result));}
              return true;
          };
      } break;
      case 215: { // _embedding_bag
      
          run_op = [=] {
              auto weight = peek(0, 3);
              auto indices = peek(1, 3);
              auto offsets = peek(2, 3);
              auto the_result = at::_embedding_bag(weight, indices, offsets);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
                if(OutputSize() > 3) {assignTo(Output(3),std::get<3>(the_result));}
              return true;
          };
      } break;
      case 216: { // _embedding_bag_backward
          int64_t num_weights = readAttribute<int64_t>("num_weights");
          bool scale_grad_by_freq = readAttribute<int64_t>("scale_grad_by_freq");
          int64_t mode = readAttribute<int64_t>("mode");
          bool sparse = readAttribute<int64_t>("sparse");
          run_op = [=] {
              auto grad = peek(0, 7);
              auto indices = peek(1, 7);
              auto offsets = peek(2, 7);
              auto offset2bag = peek(3, 7);
              auto bag_size = peek(4, 7);
              auto maximum_indices = peek(5, 7);
              auto per_sample_weights = peek(6, 7);
              auto the_result = at::_embedding_bag_backward(grad, indices, offsets, offset2bag, bag_size, maximum_indices, num_weights, scale_grad_by_freq, mode, sparse, per_sample_weights);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 217: { // _embedding_bag_sparse_backward
          int64_t num_weights = readAttribute<int64_t>("num_weights");
          bool scale_grad_by_freq = readAttribute<int64_t>("scale_grad_by_freq");
          int64_t mode = readAttribute<int64_t>("mode");
          run_op = [=] {
              auto grad = peek(0, 6);
              auto indices = peek(1, 6);
              auto offsets = peek(2, 6);
              auto offset2bag = peek(3, 6);
              auto bag_size = peek(4, 6);
              auto per_sample_weights = peek(5, 6);
              auto the_result = at::_embedding_bag_sparse_backward(grad, indices, offsets, offset2bag, bag_size, num_weights, scale_grad_by_freq, mode, per_sample_weights);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 218: { // _embedding_bag_dense_backward
          int64_t num_weights = readAttribute<int64_t>("num_weights");
          bool scale_grad_by_freq = readAttribute<int64_t>("scale_grad_by_freq");
          int64_t mode = readAttribute<int64_t>("mode");
          run_op = [=] {
              auto grad = peek(0, 7);
              auto indices = peek(1, 7);
              auto offsets = peek(2, 7);
              auto offset2bag = peek(3, 7);
              auto bag_size = peek(4, 7);
              auto maximum_indices = peek(5, 7);
              auto per_sample_weights = peek(6, 7);
              auto the_result = at::_embedding_bag_dense_backward(grad, indices, offsets, offset2bag, bag_size, maximum_indices, num_weights, scale_grad_by_freq, mode, per_sample_weights);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 219: { // _embedding_bag_per_sample_weights_backward
          int64_t mode = readAttribute<int64_t>("mode");
          run_op = [=] {
              auto grad = peek(0, 5);
              auto weight = peek(1, 5);
              auto indices = peek(2, 5);
              auto offsets = peek(3, 5);
              auto offset2bag = peek(4, 5);
              auto the_result = at::_embedding_bag_per_sample_weights_backward(grad, weight, indices, offsets, offset2bag, mode);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 220: { // erf
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::erf(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 221: { // erfc
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::erfc(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 222: { // exp
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::exp(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 223: { // expm1
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::expm1(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 224: { // expand
          auto size = readIntArrayRef("size");
          bool implicit = readAttribute<int64_t>("implicit");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self.expand(size, implicit);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 225: { // expand
          auto size = readIntArrayRef("size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self.expand(size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 226: { // expand_as
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = self.expand_as(other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 227: { // flatten
          int64_t start_dim = readAttribute<int64_t>("start_dim");
          int64_t end_dim = readAttribute<int64_t>("end_dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::flatten(self, start_dim, end_dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 228: { // flatten
          int64_t start_dim = readAttribute<int64_t>("start_dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::flatten(self, start_dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 229: { // flatten
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::flatten(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 230: { // floor
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::floor(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 231: { // frac
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::frac(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 232: { // grid_sampler
          int64_t interpolation_mode = readAttribute<int64_t>("interpolation_mode");
          int64_t padding_mode = readAttribute<int64_t>("padding_mode");
          run_op = [=] {
              auto input = peek(0, 2);
              auto grid = peek(1, 2);
              auto the_result = at::grid_sampler(input, grid, interpolation_mode, padding_mode);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 233: { // grid_sampler_2d
          int64_t interpolation_mode = readAttribute<int64_t>("interpolation_mode");
          int64_t padding_mode = readAttribute<int64_t>("padding_mode");
          run_op = [=] {
              auto input = peek(0, 2);
              auto grid = peek(1, 2);
              auto the_result = at::grid_sampler_2d(input, grid, interpolation_mode, padding_mode);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 234: { // grid_sampler_2d_backward
          int64_t interpolation_mode = readAttribute<int64_t>("interpolation_mode");
          int64_t padding_mode = readAttribute<int64_t>("padding_mode");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto input = peek(1, 3);
              auto grid = peek(2, 3);
              auto the_result = at::grid_sampler_2d_backward(grad_output, input, grid, interpolation_mode, padding_mode);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 235: { // grid_sampler_3d
          int64_t interpolation_mode = readAttribute<int64_t>("interpolation_mode");
          int64_t padding_mode = readAttribute<int64_t>("padding_mode");
          run_op = [=] {
              auto input = peek(0, 2);
              auto grid = peek(1, 2);
              auto the_result = at::grid_sampler_3d(input, grid, interpolation_mode, padding_mode);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 236: { // grid_sampler_3d_backward
          int64_t interpolation_mode = readAttribute<int64_t>("interpolation_mode");
          int64_t padding_mode = readAttribute<int64_t>("padding_mode");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto input = peek(1, 3);
              auto grid = peek(2, 3);
              auto the_result = at::grid_sampler_3d_backward(grad_output, input, grid, interpolation_mode, padding_mode);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 237: { // hinge_embedding_loss
          double margin = readAttribute<float>("margin");
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::hinge_embedding_loss(self, target, margin, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 238: { // hinge_embedding_loss
          double margin = readAttribute<float>("margin");
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::hinge_embedding_loss(self, target, margin);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 239: { // hinge_embedding_loss
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::hinge_embedding_loss(self, target);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 240: { // ger
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto vec2 = peek(1, 2);
              auto the_result = at::ger(self, vec2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 241: { // group_norm
          int64_t num_groups = readAttribute<int64_t>("num_groups");
          double eps = readAttribute<float>("eps");
          bool cudnn_enabled = readAttribute<int64_t>("cudnn_enabled");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::group_norm(input, num_groups, weight, bias, eps, cudnn_enabled);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 242: { // group_norm
          int64_t num_groups = readAttribute<int64_t>("num_groups");
          double eps = readAttribute<float>("eps");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::group_norm(input, num_groups, weight, bias, eps);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 243: { // group_norm
          int64_t num_groups = readAttribute<int64_t>("num_groups");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::group_norm(input, num_groups, weight, bias);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 244: { // group_norm
          int64_t num_groups = readAttribute<int64_t>("num_groups");
          run_op = [=] {
              auto input = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::group_norm(input, num_groups, weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 245: { // group_norm
          int64_t num_groups = readAttribute<int64_t>("num_groups");
          run_op = [=] {
              auto input = peek(0, 1);
              auto the_result = at::group_norm(input, num_groups);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 246: { // fft
          int64_t signal_ndim = readAttribute<int64_t>("signal_ndim");
          bool normalized = readAttribute<int64_t>("normalized");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::fft(self, signal_ndim, normalized);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 247: { // fft
          int64_t signal_ndim = readAttribute<int64_t>("signal_ndim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::fft(self, signal_ndim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 248: { // ifft
          int64_t signal_ndim = readAttribute<int64_t>("signal_ndim");
          bool normalized = readAttribute<int64_t>("normalized");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::ifft(self, signal_ndim, normalized);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 249: { // ifft
          int64_t signal_ndim = readAttribute<int64_t>("signal_ndim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::ifft(self, signal_ndim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 250: { // rfft
          int64_t signal_ndim = readAttribute<int64_t>("signal_ndim");
          bool normalized = readAttribute<int64_t>("normalized");
          bool onesided = readAttribute<int64_t>("onesided");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::rfft(self, signal_ndim, normalized, onesided);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 251: { // rfft
          int64_t signal_ndim = readAttribute<int64_t>("signal_ndim");
          bool normalized = readAttribute<int64_t>("normalized");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::rfft(self, signal_ndim, normalized);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 252: { // rfft
          int64_t signal_ndim = readAttribute<int64_t>("signal_ndim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::rfft(self, signal_ndim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 253: { // irfft
          int64_t signal_ndim = readAttribute<int64_t>("signal_ndim");
          bool normalized = readAttribute<int64_t>("normalized");
          bool onesided = readAttribute<int64_t>("onesided");
          auto signal_sizes = readIntArrayRef("signal_sizes");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::irfft(self, signal_ndim, normalized, onesided, signal_sizes);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 254: { // irfft
          int64_t signal_ndim = readAttribute<int64_t>("signal_ndim");
          bool normalized = readAttribute<int64_t>("normalized");
          bool onesided = readAttribute<int64_t>("onesided");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::irfft(self, signal_ndim, normalized, onesided);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 255: { // irfft
          int64_t signal_ndim = readAttribute<int64_t>("signal_ndim");
          bool normalized = readAttribute<int64_t>("normalized");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::irfft(self, signal_ndim, normalized);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 256: { // irfft
          int64_t signal_ndim = readAttribute<int64_t>("signal_ndim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::irfft(self, signal_ndim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 257: { // _fft_with_size
          int64_t signal_ndim = readAttribute<int64_t>("signal_ndim");
          bool complex_input = readAttribute<int64_t>("complex_input");
          bool complex_output = readAttribute<int64_t>("complex_output");
          bool inverse = readAttribute<int64_t>("inverse");
          auto checked_signal_sizes = readIntArrayRef("checked_signal_sizes");
          bool normalized = readAttribute<int64_t>("normalized");
          bool onesided = readAttribute<int64_t>("onesided");
          auto output_sizes = readIntArrayRef("output_sizes");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_fft_with_size(self, signal_ndim, complex_input, complex_output, inverse, checked_signal_sizes, normalized, onesided, output_sizes);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 258: { // _cufft_get_plan_cache_size
          int64_t device_index = readAttribute<int64_t>("device_index");
          run_op = [=] {
      
              auto the_result = at::_cufft_get_plan_cache_size(device_index);
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 259: { // _cufft_get_plan_cache_max_size
          int64_t device_index = readAttribute<int64_t>("device_index");
          run_op = [=] {
      
              auto the_result = at::_cufft_get_plan_cache_max_size(device_index);
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 260: { // index
      
          run_op = [=] {
              auto self = peek(0, InputSize());
              auto indices = peekSlice(1, InputSize() - 1, InputSize());
              auto the_result = at::index(self, indices);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 261: { // index_copy
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 3);
              auto index = peek(1, 3);
              auto source = peek(2, 3);
              auto the_result = at::index_copy(self, dim, index, source);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 262: { // index_put
          bool accumulate = readAttribute<int64_t>("accumulate");
          run_op = [=] {
              auto self = peek(0, InputSize());
              auto indices = peekSlice(1, InputSize() - 2, InputSize());
              auto values = peek(1, 2);
              auto the_result = at::index_put(self, indices, values, accumulate);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 263: { // index_put
      
          run_op = [=] {
              auto self = peek(0, InputSize());
              auto indices = peekSlice(1, InputSize() - 2, InputSize());
              auto values = peek(1, 2);
              auto the_result = at::index_put(self, indices, values);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 264: { // instance_norm
          bool use_input_stats = readAttribute<int64_t>("use_input_stats");
          double momentum = readAttribute<float>("momentum");
          double eps = readAttribute<float>("eps");
          bool cudnn_enabled = readAttribute<int64_t>("cudnn_enabled");
          run_op = [=] {
              auto input = peek(0, 5);
              auto weight = peek(1, 5);
              auto bias = peek(2, 5);
              auto running_mean = peek(3, 5);
              auto running_var = peek(4, 5);
              auto the_result = at::instance_norm(input, weight, bias, running_mean, running_var, use_input_stats, momentum, eps, cudnn_enabled);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 265: { // inverse
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::inverse(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 266: { // _inverse_helper
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_inverse_helper(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 267: { // isclose
          double rtol = readAttribute<float>("rtol");
          double atol = readAttribute<float>("atol");
          bool equal_nan = readAttribute<int64_t>("equal_nan");
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::isclose(self, other, rtol, atol, equal_nan);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 268: { // isclose
          double rtol = readAttribute<float>("rtol");
          double atol = readAttribute<float>("atol");
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::isclose(self, other, rtol, atol);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 269: { // isclose
          double rtol = readAttribute<float>("rtol");
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::isclose(self, other, rtol);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 270: { // isclose
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::isclose(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 271: { // isnan
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::isnan(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 272: { // is_distributed
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::is_distributed(self);
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 273: { // is_floating_point
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::is_floating_point(self);
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 274: { // is_complex
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::is_complex(self);
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 275: { // is_nonzero
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::is_nonzero(self);
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 276: { // is_same_size
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::is_same_size(self, other);
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 277: { // is_signed
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::is_signed(self);
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 278: { // kl_div
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::kl_div(self, target, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 279: { // kl_div
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::kl_div(self, target);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 280: { // kl_div_backward
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto target = peek(2, 3);
              auto the_result = at::kl_div_backward(grad_output, self, target, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 281: { // kl_div_backward
      
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto target = peek(2, 3);
              auto the_result = at::kl_div_backward(grad_output, self, target);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 282: { // kthvalue
          int64_t k = readAttribute<int64_t>("k");
          int64_t dim = readAttribute<int64_t>("dim");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::kthvalue(self, k, dim, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 283: { // kthvalue
          int64_t k = readAttribute<int64_t>("k");
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::kthvalue(self, k, dim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 284: { // kthvalue
          int64_t k = readAttribute<int64_t>("k");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::kthvalue(self, k);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 285: { // layer_norm
          auto normalized_shape = readIntArrayRef("normalized_shape");
          double eps = readAttribute<float>("eps");
          bool cudnn_enable = readAttribute<int64_t>("cudnn_enable");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::layer_norm(input, normalized_shape, weight, bias, eps, cudnn_enable);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 286: { // layer_norm
          auto normalized_shape = readIntArrayRef("normalized_shape");
          double eps = readAttribute<float>("eps");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::layer_norm(input, normalized_shape, weight, bias, eps);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 287: { // layer_norm
          auto normalized_shape = readIntArrayRef("normalized_shape");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::layer_norm(input, normalized_shape, weight, bias);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 288: { // layer_norm
          auto normalized_shape = readIntArrayRef("normalized_shape");
          run_op = [=] {
              auto input = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::layer_norm(input, normalized_shape, weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 289: { // layer_norm
          auto normalized_shape = readIntArrayRef("normalized_shape");
          run_op = [=] {
              auto input = peek(0, 1);
              auto the_result = at::layer_norm(input, normalized_shape);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 290: { // native_layer_norm
          int64_t M = readAttribute<int64_t>("M");
          int64_t N = readAttribute<int64_t>("N");
          double eps = readAttribute<float>("eps");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::native_layer_norm(input, weight, bias, M, N, eps);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 291: { // native_layer_norm_backward
          int64_t M = readAttribute<int64_t>("M");
          int64_t N = readAttribute<int64_t>("N");
          auto output_mask = readBoolMask<3>("output_mask");
          run_op = [=] {
              auto grad_out = peek(0, 5);
              auto input = peek(1, 5);
              auto mean = peek(2, 5);
              auto rstd = peek(3, 5);
              auto weight = peek(4, 5);
              auto the_result = at::native_layer_norm_backward(grad_out, input, mean, rstd, weight, M, N, output_mask);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 292: { // native_layer_norm_double_backward
          int64_t M = readAttribute<int64_t>("M");
          int64_t N = readAttribute<int64_t>("N");
          auto output_mask = readBoolMask<3>("output_mask");
          run_op = [=] {
              auto ggI = peek(0, 8);
              auto ggW = peek(1, 8);
              auto ggb = peek(2, 8);
              auto gO = peek(3, 8);
              auto input = peek(4, 8);
              auto mean = peek(5, 8);
              auto rstd = peek(6, 8);
              auto weight = peek(7, 8);
              auto the_result = at::native_layer_norm_double_backward(ggI, ggW, ggb, gO, input, mean, rstd, weight, M, N, output_mask);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 293: { // linear
      
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::linear(input, weight, bias);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 294: { // linear
      
          run_op = [=] {
              auto input = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::linear(input, weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 295: { // mkldnn_linear
      
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::mkldnn_linear(input, weight, bias);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 296: { // mkldnn_linear
      
          run_op = [=] {
              auto input = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::mkldnn_linear(input, weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 297: { // fbgemm_linear_int8_weight_fp32_activation
          at::Scalar weight_scale = readScalarAttribute("weight_scale");
          at::Scalar weight_zero_point = readScalarAttribute("weight_zero_point");
          run_op = [=] {
              auto input = peek(0, 5);
              auto weight = peek(1, 5);
              auto packed = peek(2, 5);
              auto col_offsets = peek(3, 5);
              auto bias = peek(4, 5);
              auto the_result = at::fbgemm_linear_int8_weight_fp32_activation(input, weight, packed, col_offsets, weight_scale, weight_zero_point, bias);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 298: { // fbgemm_linear_int8_weight
          at::Scalar weight_scale = readScalarAttribute("weight_scale");
          at::Scalar weight_zero_point = readScalarAttribute("weight_zero_point");
          run_op = [=] {
              auto input = peek(0, 5);
              auto weight = peek(1, 5);
              auto packed = peek(2, 5);
              auto col_offsets = peek(3, 5);
              auto bias = peek(4, 5);
              auto the_result = at::fbgemm_linear_int8_weight(input, weight, packed, col_offsets, weight_scale, weight_zero_point, bias);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 299: { // fbgemm_pack_gemm_matrix_fp16
      
          run_op = [=] {
              auto input = peek(0, 1);
              auto the_result = at::fbgemm_pack_gemm_matrix_fp16(input);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 300: { // fbgemm_linear_fp16_weight_fp32_activation
      
          run_op = [=] {
              auto input = peek(0, 3);
              auto packed_weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::fbgemm_linear_fp16_weight_fp32_activation(input, packed_weight, bias);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 301: { // fbgemm_linear_fp16_weight
      
          run_op = [=] {
              auto input = peek(0, 3);
              auto packed_weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::fbgemm_linear_fp16_weight(input, packed_weight, bias);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 302: { // fbgemm_pack_quantized_matrix
      
          run_op = [=] {
              auto input = peek(0, 1);
              auto the_result = at::fbgemm_pack_quantized_matrix(input);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 303: { // fbgemm_pack_quantized_matrix
          int64_t K = readAttribute<int64_t>("K");
          int64_t N = readAttribute<int64_t>("N");
          run_op = [=] {
              auto input = peek(0, 1);
              auto the_result = at::fbgemm_pack_quantized_matrix(input, K, N);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 304: { // fbgemm_is_cpu_supported
      
          run_op = [=] {
      
              auto the_result = at::fbgemm_is_cpu_supported();
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 305: { // log
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::log(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 306: { // log10
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::log10(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 307: { // log1p
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::log1p(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 308: { // log2
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::log2(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 309: { // logdet
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::logdet(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 310: { // log_softmax
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::log_softmax(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 311: { // _log_softmax
          int64_t dim = readAttribute<int64_t>("dim");
          bool half_to_float = readAttribute<int64_t>("half_to_float");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_log_softmax(self, dim, half_to_float);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 312: { // _log_softmax_backward_data
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto output = peek(1, 3);
              auto self = peek(2, 3);
              auto the_result = at::_log_softmax_backward_data(grad_output, output, dim, self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 313: { // logsumexp
          auto dim = readIntArrayRef("dim");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::logsumexp(self, dim, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 314: { // logsumexp
          auto dim = readIntArrayRef("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::logsumexp(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 315: { // margin_ranking_loss
          double margin = readAttribute<float>("margin");
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto input1 = peek(0, 3);
              auto input2 = peek(1, 3);
              auto target = peek(2, 3);
              auto the_result = at::margin_ranking_loss(input1, input2, target, margin, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 316: { // margin_ranking_loss
          double margin = readAttribute<float>("margin");
          run_op = [=] {
              auto input1 = peek(0, 3);
              auto input2 = peek(1, 3);
              auto target = peek(2, 3);
              auto the_result = at::margin_ranking_loss(input1, input2, target, margin);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 317: { // margin_ranking_loss
      
          run_op = [=] {
              auto input1 = peek(0, 3);
              auto input2 = peek(1, 3);
              auto target = peek(2, 3);
              auto the_result = at::margin_ranking_loss(input1, input2, target);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 318: { // matmul
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::matmul(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 319: { // matrix_rank
          double tol = readAttribute<float>("tol");
          bool symmetric = readAttribute<int64_t>("symmetric");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::matrix_rank(self, tol, symmetric);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 320: { // matrix_rank
          double tol = readAttribute<float>("tol");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::matrix_rank(self, tol);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 321: { // matrix_rank
          bool symmetric = readAttribute<int64_t>("symmetric");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::matrix_rank(self, symmetric);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 322: { // matrix_rank
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::matrix_rank(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 323: { // matrix_power
          int64_t n = readAttribute<int64_t>("n");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::matrix_power(self, n);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 324: { // max
          int64_t dim = readAttribute<int64_t>("dim");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max(self, dim, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 325: { // max
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 326: { // max_values
          auto dim = readIntArrayRef("dim");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_values(self, dim, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 327: { // max_values
          auto dim = readIntArrayRef("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_values(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 328: { // max_pool1d_with_indices
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          bool ceil_mode = readAttribute<int64_t>("ceil_mode");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool1d_with_indices(self, kernel_size, stride, padding, dilation, ceil_mode);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 329: { // max_pool1d_with_indices
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool1d_with_indices(self, kernel_size, stride, padding, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 330: { // max_pool1d_with_indices
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool1d_with_indices(self, kernel_size, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 331: { // max_pool1d_with_indices
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool1d_with_indices(self, kernel_size, stride);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 332: { // max_pool1d_with_indices
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool1d_with_indices(self, kernel_size);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 333: { // max_pool1d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          bool ceil_mode = readAttribute<int64_t>("ceil_mode");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool1d(self, kernel_size, stride, padding, dilation, ceil_mode);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 334: { // max_pool1d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool1d(self, kernel_size, stride, padding, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 335: { // max_pool1d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool1d(self, kernel_size, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 336: { // max_pool1d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool1d(self, kernel_size, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 337: { // max_pool1d
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool1d(self, kernel_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 338: { // max_pool2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          bool ceil_mode = readAttribute<int64_t>("ceil_mode");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool2d(self, kernel_size, stride, padding, dilation, ceil_mode);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 339: { // max_pool2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool2d(self, kernel_size, stride, padding, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 340: { // max_pool2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool2d(self, kernel_size, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 341: { // max_pool2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool2d(self, kernel_size, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 342: { // max_pool2d
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool2d(self, kernel_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 343: { // mkldnn_max_pool2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          bool ceil_mode = readAttribute<int64_t>("ceil_mode");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::mkldnn_max_pool2d(self, kernel_size, stride, padding, dilation, ceil_mode);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 344: { // mkldnn_max_pool2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::mkldnn_max_pool2d(self, kernel_size, stride, padding, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 345: { // mkldnn_max_pool2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::mkldnn_max_pool2d(self, kernel_size, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 346: { // mkldnn_max_pool2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::mkldnn_max_pool2d(self, kernel_size, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 347: { // mkldnn_max_pool2d
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::mkldnn_max_pool2d(self, kernel_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 348: { // quantized_max_pool2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::quantized_max_pool2d(self, kernel_size, stride, padding, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 349: { // quantized_max_pool2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::quantized_max_pool2d(self, kernel_size, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 350: { // quantized_max_pool2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::quantized_max_pool2d(self, kernel_size, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 351: { // quantized_max_pool2d
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::quantized_max_pool2d(self, kernel_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 352: { // max_pool3d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          bool ceil_mode = readAttribute<int64_t>("ceil_mode");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool3d(self, kernel_size, stride, padding, dilation, ceil_mode);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 353: { // max_pool3d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool3d(self, kernel_size, stride, padding, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 354: { // max_pool3d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool3d(self, kernel_size, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 355: { // max_pool3d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool3d(self, kernel_size, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 356: { // max_pool3d
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool3d(self, kernel_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 357: { // mean
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::mean(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 358: { // mean
          auto dim = readIntArrayRef("dim");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::mean(self, dim, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 359: { // mean
          auto dim = readIntArrayRef("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::mean(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 360: { // median
          int64_t dim = readAttribute<int64_t>("dim");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::median(self, dim, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 361: { // median
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::median(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 362: { // min
          int64_t dim = readAttribute<int64_t>("dim");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::min(self, dim, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 363: { // min
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::min(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 364: { // min_values
          auto dim = readIntArrayRef("dim");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::min_values(self, dim, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 365: { // min_values
          auto dim = readIntArrayRef("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::min_values(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 366: { // mkldnn_convolution
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::mkldnn_convolution(self, weight, bias, padding, stride, dilation, groups);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 367: { // mkldnn_convolution_backward_input
          auto self_size = readIntArrayRef("self_size");
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          bool bias_defined = readAttribute<int64_t>("bias_defined");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::mkldnn_convolution_backward_input(self_size, grad_output, weight, padding, stride, dilation, groups, bias_defined);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 368: { // mkldnn_convolution_backward_weights
          auto weight_size = readIntArrayRef("weight_size");
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          bool bias_defined = readAttribute<int64_t>("bias_defined");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::mkldnn_convolution_backward_weights(weight_size, grad_output, self, padding, stride, dilation, groups, bias_defined);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 369: { // mkldnn_convolution_backward
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          auto output_mask = readBoolMask<3>("output_mask");
          run_op = [=] {
              auto self = peek(0, 3);
              auto grad_output = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::mkldnn_convolution_backward(self, grad_output, weight, padding, stride, dilation, groups, output_mask);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 370: { // miopen_batch_norm
          bool training = readAttribute<int64_t>("training");
          double exponential_average_factor = readAttribute<float>("exponential_average_factor");
          double epsilon = readAttribute<float>("epsilon");
          run_op = [=] {
              auto input = peek(0, 5);
              auto weight = peek(1, 5);
              auto bias = peek(2, 5);
              auto running_mean = peek(3, 5);
              auto running_var = peek(4, 5);
              auto the_result = at::miopen_batch_norm(input, weight, bias, running_mean, running_var, training, exponential_average_factor, epsilon);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 371: { // miopen_batch_norm_backward
          double epsilon = readAttribute<float>("epsilon");
          run_op = [=] {
              auto input = peek(0, 7);
              auto grad_output = peek(1, 7);
              auto weight = peek(2, 7);
              auto running_mean = peek(3, 7);
              auto running_var = peek(4, 7);
              auto save_mean = peek(5, 7);
              auto save_var = peek(6, 7);
              auto the_result = at::miopen_batch_norm_backward(input, grad_output, weight, running_mean, running_var, save_mean, save_var, epsilon);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 372: { // miopen_convolution
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          bool benchmark = readAttribute<int64_t>("benchmark");
          bool deterministic = readAttribute<int64_t>("deterministic");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::miopen_convolution(self, weight, bias, padding, stride, dilation, groups, benchmark, deterministic);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 373: { // miopen_convolution_backward_input
          auto self_size = readIntArrayRef("self_size");
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          bool benchmark = readAttribute<int64_t>("benchmark");
          bool deterministic = readAttribute<int64_t>("deterministic");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::miopen_convolution_backward_input(self_size, grad_output, weight, padding, stride, dilation, groups, benchmark, deterministic);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 374: { // miopen_convolution_backward
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          bool benchmark = readAttribute<int64_t>("benchmark");
          bool deterministic = readAttribute<int64_t>("deterministic");
          auto output_mask = readBoolMask<3>("output_mask");
          run_op = [=] {
              auto self = peek(0, 3);
              auto grad_output = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::miopen_convolution_backward(self, grad_output, weight, padding, stride, dilation, groups, benchmark, deterministic, output_mask);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 375: { // miopen_convolution_backward_bias
      
          run_op = [=] {
              auto grad_output = peek(0, 1);
              auto the_result = at::miopen_convolution_backward_bias(grad_output);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 376: { // miopen_convolution_backward_weight
          auto weight_size = readIntArrayRef("weight_size");
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          bool benchmark = readAttribute<int64_t>("benchmark");
          bool deterministic = readAttribute<int64_t>("deterministic");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::miopen_convolution_backward_weight(weight_size, grad_output, self, padding, stride, dilation, groups, benchmark, deterministic);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 377: { // miopen_convolution_transpose
          auto padding = readIntArrayRef("padding");
          auto output_padding = readIntArrayRef("output_padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          bool benchmark = readAttribute<int64_t>("benchmark");
          bool deterministic = readAttribute<int64_t>("deterministic");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::miopen_convolution_transpose(self, weight, bias, padding, output_padding, stride, dilation, groups, benchmark, deterministic);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 378: { // miopen_convolution_transpose_backward
          auto padding = readIntArrayRef("padding");
          auto output_padding = readIntArrayRef("output_padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          bool benchmark = readAttribute<int64_t>("benchmark");
          bool deterministic = readAttribute<int64_t>("deterministic");
          auto output_mask = readBoolMask<3>("output_mask");
          run_op = [=] {
              auto self = peek(0, 3);
              auto grad_output = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::miopen_convolution_transpose_backward(self, grad_output, weight, padding, output_padding, stride, dilation, groups, benchmark, deterministic, output_mask);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 379: { // miopen_convolution_transpose_backward_input
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          bool benchmark = readAttribute<int64_t>("benchmark");
          bool deterministic = readAttribute<int64_t>("deterministic");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::miopen_convolution_transpose_backward_input(grad_output, weight, padding, stride, dilation, groups, benchmark, deterministic);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 380: { // miopen_convolution_transpose_backward_weight
          auto weight_size = readIntArrayRef("weight_size");
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          bool benchmark = readAttribute<int64_t>("benchmark");
          bool deterministic = readAttribute<int64_t>("deterministic");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::miopen_convolution_transpose_backward_weight(weight_size, grad_output, self, padding, stride, dilation, groups, benchmark, deterministic);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 381: { // miopen_depthwise_convolution
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          bool benchmark = readAttribute<int64_t>("benchmark");
          bool deterministic = readAttribute<int64_t>("deterministic");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::miopen_depthwise_convolution(self, weight, bias, padding, stride, dilation, groups, benchmark, deterministic);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 382: { // miopen_depthwise_convolution_backward_input
          auto self_size = readIntArrayRef("self_size");
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          bool benchmark = readAttribute<int64_t>("benchmark");
          bool deterministic = readAttribute<int64_t>("deterministic");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::miopen_depthwise_convolution_backward_input(self_size, grad_output, weight, padding, stride, dilation, groups, benchmark, deterministic);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 383: { // miopen_depthwise_convolution_backward
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          bool benchmark = readAttribute<int64_t>("benchmark");
          bool deterministic = readAttribute<int64_t>("deterministic");
          auto output_mask = readBoolMask<3>("output_mask");
          run_op = [=] {
              auto self = peek(0, 3);
              auto grad_output = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::miopen_depthwise_convolution_backward(self, grad_output, weight, padding, stride, dilation, groups, benchmark, deterministic, output_mask);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 384: { // miopen_depthwise_convolution_backward_weight
          auto weight_size = readIntArrayRef("weight_size");
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          bool benchmark = readAttribute<int64_t>("benchmark");
          bool deterministic = readAttribute<int64_t>("deterministic");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::miopen_depthwise_convolution_backward_weight(weight_size, grad_output, self, padding, stride, dilation, groups, benchmark, deterministic);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 385: { // miopen_rnn
          int64_t weight_stride0 = readAttribute<int64_t>("weight_stride0");
          int64_t mode = readAttribute<int64_t>("mode");
          int64_t hidden_size = readAttribute<int64_t>("hidden_size");
          int64_t num_layers = readAttribute<int64_t>("num_layers");
          bool batch_first = readAttribute<int64_t>("batch_first");
          double dropout = readAttribute<float>("dropout");
          bool train = readAttribute<int64_t>("train");
          bool bidirectional = readAttribute<int64_t>("bidirectional");
          auto batch_sizes = readIntArrayRef("batch_sizes");
          run_op = [=] {
              auto input = peek(0, InputSize());
              auto weight = peekSlice(1, InputSize() - 4, InputSize());
              auto hx = peek(1, 4);
              auto cx = peek(2, 4);
              auto dropout_state = peek(3, 4);
              auto the_result = at::miopen_rnn(input, weight, weight_stride0, hx, cx, mode, hidden_size, num_layers, batch_first, dropout, train, bidirectional, batch_sizes, dropout_state);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
                if(OutputSize() > 3) {assignTo(Output(3),std::get<3>(the_result));}
                if(OutputSize() > 4) {assignTo(Output(4),std::get<4>(the_result));}
              return true;
          };
      } break;
      case 386: { // mm
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto mat2 = peek(1, 2);
              auto the_result = at::mm(self, mat2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 387: { // _sparse_mm
      
          run_op = [=] {
              auto sparse = peek(0, 2);
              auto dense = peek(1, 2);
              auto the_result = at::_sparse_mm(sparse, dense);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 388: { // mode
          int64_t dim = readAttribute<int64_t>("dim");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::mode(self, dim, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 389: { // mode
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::mode(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 390: { // mode
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::mode(self);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 391: { // mul
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::mul(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 392: { // mul
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::mul(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 393: { // mv
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto vec = peek(1, 2);
              auto the_result = at::mv(self, vec);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 394: { // mvlgamma
          int64_t p = readAttribute<int64_t>("p");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::mvlgamma(self, p);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 395: { // narrow_copy
          int64_t dim = readAttribute<int64_t>("dim");
          int64_t start = readAttribute<int64_t>("start");
          int64_t length = readAttribute<int64_t>("length");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self.narrow_copy(dim, start, length);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 396: { // narrow
          int64_t dim = readAttribute<int64_t>("dim");
          int64_t start = readAttribute<int64_t>("start");
          int64_t length = readAttribute<int64_t>("length");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::narrow(self, dim, start, length);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 397: { // native_batch_norm
          bool training = readAttribute<int64_t>("training");
          double momentum = readAttribute<float>("momentum");
          double eps = readAttribute<float>("eps");
          run_op = [=] {
              auto input = peek(0, 5);
              auto weight = peek(1, 5);
              auto bias = peek(2, 5);
              auto running_mean = peek(3, 5);
              auto running_var = peek(4, 5);
              auto the_result = at::native_batch_norm(input, weight, bias, running_mean, running_var, training, momentum, eps);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 398: { // batch_norm_stats
          double eps = readAttribute<float>("eps");
          run_op = [=] {
              auto input = peek(0, 1);
              auto the_result = at::batch_norm_stats(input, eps);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 399: { // batch_norm_elemt
          double eps = readAttribute<float>("eps");
          run_op = [=] {
              auto input = peek(0, 5);
              auto weight = peek(1, 5);
              auto bias = peek(2, 5);
              auto mean = peek(3, 5);
              auto invstd = peek(4, 5);
              auto the_result = at::batch_norm_elemt(input, weight, bias, mean, invstd, eps);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 400: { // batch_norm_gather_stats
          double momentum = readAttribute<float>("momentum");
          double eps = readAttribute<float>("eps");
          int64_t count = readAttribute<int64_t>("count");
          run_op = [=] {
              auto input = peek(0, 5);
              auto mean = peek(1, 5);
              auto invstd = peek(2, 5);
              auto running_mean = peek(3, 5);
              auto running_var = peek(4, 5);
              auto the_result = at::batch_norm_gather_stats(input, mean, invstd, running_mean, running_var, momentum, eps, count);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 401: { // batch_norm_gather_stats_with_counts
          double momentum = readAttribute<float>("momentum");
          double eps = readAttribute<float>("eps");
          auto counts = readIntArrayRef("counts");
          run_op = [=] {
              auto input = peek(0, 5);
              auto mean = peek(1, 5);
              auto invstd = peek(2, 5);
              auto running_mean = peek(3, 5);
              auto running_var = peek(4, 5);
              auto the_result = at::batch_norm_gather_stats_with_counts(input, mean, invstd, running_mean, running_var, momentum, eps, counts);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 402: { // native_batch_norm_backward
          bool train = readAttribute<int64_t>("train");
          double eps = readAttribute<float>("eps");
          auto output_mask = readBoolMask<3>("output_mask");
          run_op = [=] {
              auto grad_out = peek(0, 7);
              auto input = peek(1, 7);
              auto weight = peek(2, 7);
              auto running_mean = peek(3, 7);
              auto running_var = peek(4, 7);
              auto save_mean = peek(5, 7);
              auto save_invstd = peek(6, 7);
              auto the_result = at::native_batch_norm_backward(grad_out, input, weight, running_mean, running_var, save_mean, save_invstd, train, eps, output_mask);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 403: { // batch_norm_backward_reduce
          bool input_g = readAttribute<int64_t>("input_g");
          bool weight_g = readAttribute<int64_t>("weight_g");
          bool bias_g = readAttribute<int64_t>("bias_g");
          run_op = [=] {
              auto grad_out = peek(0, 4);
              auto input = peek(1, 4);
              auto mean = peek(2, 4);
              auto invstd = peek(3, 4);
              auto the_result = at::batch_norm_backward_reduce(grad_out, input, mean, invstd, input_g, weight_g, bias_g);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
                if(OutputSize() > 3) {assignTo(Output(3),std::get<3>(the_result));}
              return true;
          };
      } break;
      case 404: { // batch_norm_backward_elemt
      
          run_op = [=] {
              auto grad_out = peek(0, 7);
              auto input = peek(1, 7);
              auto mean = peek(2, 7);
              auto invstd = peek(3, 7);
              auto weight = peek(4, 7);
              auto mean_dy = peek(5, 7);
              auto mean_dy_xmu = peek(6, 7);
              auto the_result = at::batch_norm_backward_elemt(grad_out, input, mean, invstd, weight, mean_dy, mean_dy_xmu);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 405: { // batch_norm_update_stats
          double momentum = readAttribute<float>("momentum");
          run_op = [=] {
              auto input = peek(0, 3);
              auto running_mean = peek(1, 3);
              auto running_var = peek(2, 3);
              auto the_result = at::batch_norm_update_stats(input, running_mean, running_var, momentum);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 406: { // _nnpack_available
      
          run_op = [=] {
      
              auto the_result = at::_nnpack_available();
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 407: { // _nnpack_spatial_convolution
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::_nnpack_spatial_convolution(input, weight, bias, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 408: { // _nnpack_spatial_convolution_backward
          auto padding = readIntArrayRef("padding");
          auto output_mask = readBoolMask<3>("output_mask");
          run_op = [=] {
              auto input = peek(0, 3);
              auto grad_output = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::_nnpack_spatial_convolution_backward(input, grad_output, weight, padding, output_mask);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 409: { // _nnpack_spatial_convolution_backward_input
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto input = peek(0, 3);
              auto grad_output = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::_nnpack_spatial_convolution_backward_input(input, grad_output, weight, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 410: { // _nnpack_spatial_convolution_backward_weight
          auto weightsize = readIntArrayRef("weightsize");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto input = peek(0, 2);
              auto grad_output = peek(1, 2);
              auto the_result = at::_nnpack_spatial_convolution_backward_weight(input, weightsize, grad_output, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 411: { // pairwise_distance
          double p = readAttribute<float>("p");
          double eps = readAttribute<float>("eps");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto x1 = peek(0, 2);
              auto x2 = peek(1, 2);
              auto the_result = at::pairwise_distance(x1, x2, p, eps, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 412: { // pairwise_distance
          double p = readAttribute<float>("p");
          double eps = readAttribute<float>("eps");
          run_op = [=] {
              auto x1 = peek(0, 2);
              auto x2 = peek(1, 2);
              auto the_result = at::pairwise_distance(x1, x2, p, eps);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 413: { // pairwise_distance
          double p = readAttribute<float>("p");
          run_op = [=] {
              auto x1 = peek(0, 2);
              auto x2 = peek(1, 2);
              auto the_result = at::pairwise_distance(x1, x2, p);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 414: { // pairwise_distance
      
          run_op = [=] {
              auto x1 = peek(0, 2);
              auto x2 = peek(1, 2);
              auto the_result = at::pairwise_distance(x1, x2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 415: { // cdist
          double p = readAttribute<float>("p");
          run_op = [=] {
              auto x1 = peek(0, 2);
              auto x2 = peek(1, 2);
              auto the_result = at::cdist(x1, x2, p);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 416: { // cdist
      
          run_op = [=] {
              auto x1 = peek(0, 2);
              auto x2 = peek(1, 2);
              auto the_result = at::cdist(x1, x2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 417: { // _cdist_backward
          double p = readAttribute<float>("p");
          run_op = [=] {
              auto grad = peek(0, 4);
              auto x1 = peek(1, 4);
              auto x2 = peek(2, 4);
              auto cdist = peek(3, 4);
              auto the_result = at::_cdist_backward(grad, x1, x2, p, cdist);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 418: { // pdist
          double p = readAttribute<float>("p");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::pdist(self, p);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 419: { // pdist
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::pdist(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 420: { // _pdist_forward
          double p = readAttribute<float>("p");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_pdist_forward(self, p);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 421: { // _pdist_forward
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_pdist_forward(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 422: { // _pdist_backward
          double p = readAttribute<float>("p");
          run_op = [=] {
              auto grad = peek(0, 3);
              auto self = peek(1, 3);
              auto pdist = peek(2, 3);
              auto the_result = at::_pdist_backward(grad, self, p, pdist);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 423: { // cosine_similarity
          int64_t dim = readAttribute<int64_t>("dim");
          double eps = readAttribute<float>("eps");
          run_op = [=] {
              auto x1 = peek(0, 2);
              auto x2 = peek(1, 2);
              auto the_result = at::cosine_similarity(x1, x2, dim, eps);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 424: { // cosine_similarity
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto x1 = peek(0, 2);
              auto x2 = peek(1, 2);
              auto the_result = at::cosine_similarity(x1, x2, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 425: { // cosine_similarity
      
          run_op = [=] {
              auto x1 = peek(0, 2);
              auto x2 = peek(1, 2);
              auto the_result = at::cosine_similarity(x1, x2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 426: { // permute
          auto dims = readIntArrayRef("dims");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self.permute(dims);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 427: { // numpy_T
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self.numpy_T();
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 428: { // pixel_shuffle
          int64_t upscale_factor = readAttribute<int64_t>("upscale_factor");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::pixel_shuffle(self, upscale_factor);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 429: { // is_pinned
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self.is_pinned();
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 430: { // pin_memory
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self.pin_memory();
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 431: { // pinverse
          double rcond = readAttribute<float>("rcond");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::pinverse(self, rcond);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 432: { // pinverse
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::pinverse(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 433: { // poisson_nll_loss
          bool log_input = readAttribute<int64_t>("log_input");
          bool full = readAttribute<int64_t>("full");
          double eps = readAttribute<float>("eps");
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto input = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::poisson_nll_loss(input, target, log_input, full, eps, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 434: { // reciprocal
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::reciprocal(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 435: { // neg
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::neg(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 436: { // repeat
          auto repeats = readIntArrayRef("repeats");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self.repeat(repeats);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 437: { // repeat_interleave
      
          run_op = [=] {
              auto repeats = peek(0, 1);
              auto the_result = at::repeat_interleave(repeats);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 438: { // repeat_interleave
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto repeats = peek(1, 2);
              auto the_result = at::repeat_interleave(self, repeats);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 439: { // repeat_interleave
          int64_t repeats = readAttribute<int64_t>("repeats");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::repeat_interleave(self, repeats);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 440: { // reshape
          auto shape = readIntArrayRef("shape");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::reshape(self, shape);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 441: { // _mkldnn_reshape
          auto shape = readIntArrayRef("shape");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_mkldnn_reshape(self, shape);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 442: { // reshape_as
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = self.reshape_as(other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 443: { // round
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::round(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 444: { // rrelu
          at::Scalar lower = readScalarAttribute("lower");
          at::Scalar upper = readScalarAttribute("upper");
          bool training = readAttribute<int64_t>("training");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::rrelu(self, lower, upper, training);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 445: { // rrelu
          at::Scalar lower = readScalarAttribute("lower");
          at::Scalar upper = readScalarAttribute("upper");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::rrelu(self, lower, upper);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 446: { // rrelu
          at::Scalar lower = readScalarAttribute("lower");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::rrelu(self, lower);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 447: { // rrelu
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::rrelu(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 448: { // relu
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::relu(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 449: { // prelu
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::prelu(self, weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 450: { // prelu_backward
      
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::prelu_backward(grad_output, self, weight);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 451: { // gelu
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::gelu(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 452: { // gelu_backward
      
          run_op = [=] {
              auto grad = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::gelu_backward(grad, self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 453: { // hardshrink
          at::Scalar lambd = readScalarAttribute("lambd");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::hardshrink(self, lambd);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 454: { // hardshrink
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::hardshrink(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 455: { // hardshrink_backward
          at::Scalar lambd = readScalarAttribute("lambd");
          run_op = [=] {
              auto grad_out = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::hardshrink_backward(grad_out, self, lambd);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 456: { // rsqrt
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::rsqrt(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 457: { // select
          int64_t dim = readAttribute<int64_t>("dim");
          int64_t index = readAttribute<int64_t>("index");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::select(self, dim, index);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 458: { // selu
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::selu(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 459: { // celu
          at::Scalar alpha = readScalarAttribute("alpha");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::celu(self, alpha);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 460: { // celu
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::celu(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 461: { // sigmoid
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::sigmoid(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 462: { // sin
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::sin(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 463: { // sinh
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::sinh(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 464: { // detach
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::detach(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 465: { // size
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::size(self, dim);
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 466: { // slice
          int64_t dim = readAttribute<int64_t>("dim");
          int64_t start = readAttribute<int64_t>("start");
          int64_t end = readAttribute<int64_t>("end");
          int64_t step = readAttribute<int64_t>("step");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::slice(self, dim, start, end, step);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 467: { // slice
          int64_t dim = readAttribute<int64_t>("dim");
          int64_t start = readAttribute<int64_t>("start");
          int64_t end = readAttribute<int64_t>("end");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::slice(self, dim, start, end);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 468: { // slice
          int64_t dim = readAttribute<int64_t>("dim");
          int64_t start = readAttribute<int64_t>("start");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::slice(self, dim, start);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 469: { // slice
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::slice(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 470: { // slice
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::slice(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 471: { // slogdet
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::slogdet(self);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 472: { // smm
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto mat2 = peek(1, 2);
              auto the_result = at::smm(self, mat2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 473: { // softmax
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::softmax(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 474: { // _softmax
          int64_t dim = readAttribute<int64_t>("dim");
          bool half_to_float = readAttribute<int64_t>("half_to_float");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_softmax(self, dim, half_to_float);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 475: { // _softmax_backward_data
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto output = peek(1, 3);
              auto self = peek(2, 3);
              auto the_result = at::_softmax_backward_data(grad_output, output, dim, self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 476: { // split
          int64_t split_size = readAttribute<int64_t>("split_size");
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::split(self, split_size, dim);
                if(OutputSize() > 0) {assignListStartingAt(0, the_result);}
              return true;
          };
      } break;
      case 477: { // split
          int64_t split_size = readAttribute<int64_t>("split_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::split(self, split_size);
                if(OutputSize() > 0) {assignListStartingAt(0, the_result);}
              return true;
          };
      } break;
      case 478: { // split_with_sizes
          auto split_sizes = readIntArrayRef("split_sizes");
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::split_with_sizes(self, split_sizes, dim);
                if(OutputSize() > 0) {assignListStartingAt(0, the_result);}
              return true;
          };
      } break;
      case 479: { // split_with_sizes
          auto split_sizes = readIntArrayRef("split_sizes");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::split_with_sizes(self, split_sizes);
                if(OutputSize() > 0) {assignListStartingAt(0, the_result);}
              return true;
          };
      } break;
      case 480: { // squeeze
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::squeeze(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 481: { // squeeze
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::squeeze(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 482: { // sspaddmm
          at::Scalar beta = readScalarAttribute("beta");
          at::Scalar alpha = readScalarAttribute("alpha");
          run_op = [=] {
              auto self = peek(0, 3);
              auto mat1 = peek(1, 3);
              auto mat2 = peek(2, 3);
              auto the_result = at::sspaddmm(self, mat1, mat2, beta, alpha);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 483: { // sspaddmm
          at::Scalar beta = readScalarAttribute("beta");
          run_op = [=] {
              auto self = peek(0, 3);
              auto mat1 = peek(1, 3);
              auto mat2 = peek(2, 3);
              auto the_result = at::sspaddmm(self, mat1, mat2, beta);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 484: { // sspaddmm
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto mat1 = peek(1, 3);
              auto mat2 = peek(2, 3);
              auto the_result = at::sspaddmm(self, mat1, mat2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 485: { // stack
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto tensors = peekSlice(0, InputSize() - 0, InputSize());
              auto the_result = at::stack(tensors, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 486: { // stack
      
          run_op = [=] {
              auto tensors = peekSlice(0, InputSize() - 0, InputSize());
              auto the_result = at::stack(tensors);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 487: { // stft
          int64_t n_fft = readAttribute<int64_t>("n_fft");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::stft(self, n_fft);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 488: { // stride
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::stride(self, dim);
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 489: { // sum
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::sum(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 490: { // sum
          auto dim = readIntArrayRef("dim");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::sum(self, dim, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 491: { // sum
          auto dim = readIntArrayRef("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::sum(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 492: { // sum_to_size
          auto size = readIntArrayRef("size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self.sum_to_size(size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 493: { // sqrt
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::sqrt(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 494: { // std
          bool unbiased = readAttribute<int64_t>("unbiased");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::std(self, unbiased);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 495: { // std
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::std(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 496: { // std
          auto dim = readIntArrayRef("dim");
          bool unbiased = readAttribute<int64_t>("unbiased");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::std(self, dim, unbiased, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 497: { // std
          auto dim = readIntArrayRef("dim");
          bool unbiased = readAttribute<int64_t>("unbiased");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::std(self, dim, unbiased);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 498: { // std
          auto dim = readIntArrayRef("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::std(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 499: { // std_mean
          bool unbiased = readAttribute<int64_t>("unbiased");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::std_mean(self, unbiased);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 500: { // std_mean
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::std_mean(self);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 501: { // std_mean
          auto dim = readIntArrayRef("dim");
          bool unbiased = readAttribute<int64_t>("unbiased");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::std_mean(self, dim, unbiased, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 502: { // std_mean
          auto dim = readIntArrayRef("dim");
          bool unbiased = readAttribute<int64_t>("unbiased");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::std_mean(self, dim, unbiased);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 503: { // std_mean
          auto dim = readIntArrayRef("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::std_mean(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 504: { // prod
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::prod(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 505: { // prod
          int64_t dim = readAttribute<int64_t>("dim");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::prod(self, dim, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 506: { // prod
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::prod(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 507: { // t
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::t(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 508: { // tan
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::tan(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 509: { // tanh
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::tanh(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 510: { // tensordot
          auto dims_self = readIntArrayRef("dims_self");
          auto dims_other = readIntArrayRef("dims_other");
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::tensordot(self, other, dims_self, dims_other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 511: { // threshold
          at::Scalar threshold = readScalarAttribute("threshold");
          at::Scalar value = readScalarAttribute("value");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::threshold(self, threshold, value);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 512: { // threshold_backward
          at::Scalar threshold = readScalarAttribute("threshold");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::threshold_backward(grad_output, self, threshold);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 513: { // transpose
          int64_t dim0 = readAttribute<int64_t>("dim0");
          int64_t dim1 = readAttribute<int64_t>("dim1");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::transpose(self, dim0, dim1);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 514: { // _mkldnn_transpose
          int64_t dim0 = readAttribute<int64_t>("dim0");
          int64_t dim1 = readAttribute<int64_t>("dim1");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_mkldnn_transpose(self, dim0, dim1);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 515: { // one_hot
          int64_t num_classes = readAttribute<int64_t>("num_classes");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::one_hot(self, num_classes);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 516: { // one_hot
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::one_hot(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 517: { // flip
          auto dims = readIntArrayRef("dims");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::flip(self, dims);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 518: { // roll
          auto shifts = readIntArrayRef("shifts");
          auto dims = readIntArrayRef("dims");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::roll(self, shifts, dims);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 519: { // roll
          auto shifts = readIntArrayRef("shifts");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::roll(self, shifts);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 520: { // rot90
          int64_t k = readAttribute<int64_t>("k");
          auto dims = readIntArrayRef("dims");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::rot90(self, k, dims);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 521: { // rot90
          int64_t k = readAttribute<int64_t>("k");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::rot90(self, k);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 522: { // rot90
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::rot90(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 523: { // trapz
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto y = peek(0, 2);
              auto x = peek(1, 2);
              auto the_result = at::trapz(y, x, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 524: { // trapz
      
          run_op = [=] {
              auto y = peek(0, 2);
              auto x = peek(1, 2);
              auto the_result = at::trapz(y, x);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 525: { // trapz
          double dx = readAttribute<float>("dx");
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto y = peek(0, 1);
              auto the_result = at::trapz(y, dx, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 526: { // trapz
          double dx = readAttribute<float>("dx");
          run_op = [=] {
              auto y = peek(0, 1);
              auto the_result = at::trapz(y, dx);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 527: { // trapz
      
          run_op = [=] {
              auto y = peek(0, 1);
              auto the_result = at::trapz(y);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 528: { // _trilinear
          auto expand1 = readIntArrayRef("expand1");
          auto expand2 = readIntArrayRef("expand2");
          auto expand3 = readIntArrayRef("expand3");
          auto sumdim = readIntArrayRef("sumdim");
          int64_t unroll_dim = readAttribute<int64_t>("unroll_dim");
          run_op = [=] {
              auto i1 = peek(0, 3);
              auto i2 = peek(1, 3);
              auto i3 = peek(2, 3);
              auto the_result = at::_trilinear(i1, i2, i3, expand1, expand2, expand3, sumdim, unroll_dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 529: { // _trilinear
          auto expand1 = readIntArrayRef("expand1");
          auto expand2 = readIntArrayRef("expand2");
          auto expand3 = readIntArrayRef("expand3");
          auto sumdim = readIntArrayRef("sumdim");
          run_op = [=] {
              auto i1 = peek(0, 3);
              auto i2 = peek(1, 3);
              auto i3 = peek(2, 3);
              auto the_result = at::_trilinear(i1, i2, i3, expand1, expand2, expand3, sumdim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 530: { // triplet_margin_loss
          double margin = readAttribute<float>("margin");
          double p = readAttribute<float>("p");
          double eps = readAttribute<float>("eps");
          bool swap = readAttribute<int64_t>("swap");
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto anchor = peek(0, 3);
              auto positive = peek(1, 3);
              auto negative = peek(2, 3);
              auto the_result = at::triplet_margin_loss(anchor, positive, negative, margin, p, eps, swap, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 531: { // triplet_margin_loss
          double margin = readAttribute<float>("margin");
          double p = readAttribute<float>("p");
          double eps = readAttribute<float>("eps");
          bool swap = readAttribute<int64_t>("swap");
          run_op = [=] {
              auto anchor = peek(0, 3);
              auto positive = peek(1, 3);
              auto negative = peek(2, 3);
              auto the_result = at::triplet_margin_loss(anchor, positive, negative, margin, p, eps, swap);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 532: { // triplet_margin_loss
          double margin = readAttribute<float>("margin");
          double p = readAttribute<float>("p");
          double eps = readAttribute<float>("eps");
          run_op = [=] {
              auto anchor = peek(0, 3);
              auto positive = peek(1, 3);
              auto negative = peek(2, 3);
              auto the_result = at::triplet_margin_loss(anchor, positive, negative, margin, p, eps);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 533: { // triplet_margin_loss
          double margin = readAttribute<float>("margin");
          double p = readAttribute<float>("p");
          run_op = [=] {
              auto anchor = peek(0, 3);
              auto positive = peek(1, 3);
              auto negative = peek(2, 3);
              auto the_result = at::triplet_margin_loss(anchor, positive, negative, margin, p);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 534: { // triplet_margin_loss
          double margin = readAttribute<float>("margin");
          run_op = [=] {
              auto anchor = peek(0, 3);
              auto positive = peek(1, 3);
              auto negative = peek(2, 3);
              auto the_result = at::triplet_margin_loss(anchor, positive, negative, margin);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 535: { // triplet_margin_loss
      
          run_op = [=] {
              auto anchor = peek(0, 3);
              auto positive = peek(1, 3);
              auto negative = peek(2, 3);
              auto the_result = at::triplet_margin_loss(anchor, positive, negative);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 536: { // trunc
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::trunc(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 537: { // type_as
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = self.type_as(other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 538: { // _has_compatible_shallow_copy_type
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto from = peek(1, 2);
              auto the_result = at::_has_compatible_shallow_copy_type(self, from);
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 539: { // _unique
          bool sorted = readAttribute<int64_t>("sorted");
          bool return_inverse = readAttribute<int64_t>("return_inverse");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_unique(self, sorted, return_inverse);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 540: { // _unique
          bool sorted = readAttribute<int64_t>("sorted");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_unique(self, sorted);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 541: { // _unique
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_unique(self);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 542: { // unique_dim
          int64_t dim = readAttribute<int64_t>("dim");
          bool sorted = readAttribute<int64_t>("sorted");
          bool return_inverse = readAttribute<int64_t>("return_inverse");
          bool return_counts = readAttribute<int64_t>("return_counts");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::unique_dim(self, dim, sorted, return_inverse, return_counts);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 543: { // unique_dim
          int64_t dim = readAttribute<int64_t>("dim");
          bool sorted = readAttribute<int64_t>("sorted");
          bool return_inverse = readAttribute<int64_t>("return_inverse");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::unique_dim(self, dim, sorted, return_inverse);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 544: { // unique_dim
          int64_t dim = readAttribute<int64_t>("dim");
          bool sorted = readAttribute<int64_t>("sorted");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::unique_dim(self, dim, sorted);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 545: { // unique_dim
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::unique_dim(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 546: { // unique_consecutive
          bool return_inverse = readAttribute<int64_t>("return_inverse");
          bool return_counts = readAttribute<int64_t>("return_counts");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::unique_consecutive(self, return_inverse, return_counts);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 547: { // unique_consecutive
          bool return_inverse = readAttribute<int64_t>("return_inverse");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::unique_consecutive(self, return_inverse);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 548: { // unique_consecutive
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::unique_consecutive(self);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 549: { // unique_dim_consecutive
          int64_t dim = readAttribute<int64_t>("dim");
          bool return_inverse = readAttribute<int64_t>("return_inverse");
          bool return_counts = readAttribute<int64_t>("return_counts");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::unique_dim_consecutive(self, dim, return_inverse, return_counts);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 550: { // unique_dim_consecutive
          int64_t dim = readAttribute<int64_t>("dim");
          bool return_inverse = readAttribute<int64_t>("return_inverse");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::unique_dim_consecutive(self, dim, return_inverse);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 551: { // unique_dim_consecutive
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::unique_dim_consecutive(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 552: { // _unique2
          bool sorted = readAttribute<int64_t>("sorted");
          bool return_inverse = readAttribute<int64_t>("return_inverse");
          bool return_counts = readAttribute<int64_t>("return_counts");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_unique2(self, sorted, return_inverse, return_counts);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 553: { // _unique2
          bool sorted = readAttribute<int64_t>("sorted");
          bool return_inverse = readAttribute<int64_t>("return_inverse");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_unique2(self, sorted, return_inverse);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 554: { // _unique2
          bool sorted = readAttribute<int64_t>("sorted");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_unique2(self, sorted);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 555: { // _unique2
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_unique2(self);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 556: { // _unsafe_view
          auto size = readIntArrayRef("size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_unsafe_view(self, size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 557: { // unsqueeze
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::unsqueeze(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 558: { // var
          bool unbiased = readAttribute<int64_t>("unbiased");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::var(self, unbiased);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 559: { // var
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::var(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 560: { // var
          auto dim = readIntArrayRef("dim");
          bool unbiased = readAttribute<int64_t>("unbiased");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::var(self, dim, unbiased, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 561: { // var
          auto dim = readIntArrayRef("dim");
          bool unbiased = readAttribute<int64_t>("unbiased");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::var(self, dim, unbiased);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 562: { // var
          auto dim = readIntArrayRef("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::var(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 563: { // var_mean
          bool unbiased = readAttribute<int64_t>("unbiased");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::var_mean(self, unbiased);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 564: { // var_mean
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::var_mean(self);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 565: { // var_mean
          auto dim = readIntArrayRef("dim");
          bool unbiased = readAttribute<int64_t>("unbiased");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::var_mean(self, dim, unbiased, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 566: { // var_mean
          auto dim = readIntArrayRef("dim");
          bool unbiased = readAttribute<int64_t>("unbiased");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::var_mean(self, dim, unbiased);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 567: { // var_mean
          auto dim = readIntArrayRef("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::var_mean(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 568: { // view_as
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = self.view_as(other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 569: { // where
      
          run_op = [=] {
              auto condition = peek(0, 3);
              auto self = peek(1, 3);
              auto other = peek(2, 3);
              auto the_result = at::where(condition, self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 570: { // where
      
          run_op = [=] {
              auto condition = peek(0, 1);
              auto the_result = at::where(condition);
                if(OutputSize() > 0) {assignListStartingAt(0, the_result);}
              return true;
          };
      } break;
      case 571: { // _s_where
      
          run_op = [=] {
              auto condition = peek(0, 3);
              auto self = peek(1, 3);
              auto other = peek(2, 3);
              auto the_result = at::_s_where(condition, self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 572: { // norm_except_dim
          int64_t pow = readAttribute<int64_t>("pow");
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto v = peek(0, 1);
              auto the_result = at::norm_except_dim(v, pow, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 573: { // norm_except_dim
          int64_t pow = readAttribute<int64_t>("pow");
          run_op = [=] {
              auto v = peek(0, 1);
              auto the_result = at::norm_except_dim(v, pow);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 574: { // norm_except_dim
      
          run_op = [=] {
              auto v = peek(0, 1);
              auto the_result = at::norm_except_dim(v);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 575: { // _weight_norm
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto v = peek(0, 2);
              auto g = peek(1, 2);
              auto the_result = at::_weight_norm(v, g, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 576: { // _weight_norm
      
          run_op = [=] {
              auto v = peek(0, 2);
              auto g = peek(1, 2);
              auto the_result = at::_weight_norm(v, g);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 577: { // _weight_norm_cuda_interface
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto v = peek(0, 2);
              auto g = peek(1, 2);
              auto the_result = at::_weight_norm_cuda_interface(v, g, dim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 578: { // _weight_norm_cuda_interface
      
          run_op = [=] {
              auto v = peek(0, 2);
              auto g = peek(1, 2);
              auto the_result = at::_weight_norm_cuda_interface(v, g);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 579: { // _weight_norm_cuda_interface_backward
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto grad_w = peek(0, 4);
              auto saved_v = peek(1, 4);
              auto saved_g = peek(2, 4);
              auto saved_norms = peek(3, 4);
              auto the_result = at::_weight_norm_cuda_interface_backward(grad_w, saved_v, saved_g, saved_norms, dim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 580: { // _weight_norm_differentiable_backward
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto grad_w = peek(0, 4);
              auto saved_v = peek(1, 4);
              auto saved_g = peek(2, 4);
              auto saved_norms = peek(3, 4);
              auto the_result = at::_weight_norm_differentiable_backward(grad_w, saved_v, saved_g, saved_norms, dim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 581: { // _standard_gamma_grad
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto output = peek(1, 2);
              auto the_result = at::_standard_gamma_grad(self, output);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 582: { // _standard_gamma
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_standard_gamma(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 583: { // _dirichlet_grad
      
          run_op = [=] {
              auto x = peek(0, 3);
              auto alpha = peek(1, 3);
              auto total = peek(2, 3);
              auto the_result = at::_dirichlet_grad(x, alpha, total);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 584: { // _sample_dirichlet
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_sample_dirichlet(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 585: { // poisson
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::poisson(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 586: { // native_norm
          at::Scalar p = readScalarAttribute("p");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::native_norm(self, p);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 587: { // native_norm
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::native_norm(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 588: { // _sparse_sum
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_sparse_sum(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 589: { // _sparse_sum
          auto dim = readIntArrayRef("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_sparse_sum(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 590: { // _sparse_sum_backward
          auto dim = readIntArrayRef("dim");
          run_op = [=] {
              auto grad = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::_sparse_sum_backward(grad, self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 591: { // norm
          at::Scalar p = readScalarAttribute("p");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::norm(self, p);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 592: { // norm
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::norm(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 593: { // frobenius_norm
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::frobenius_norm(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 594: { // frobenius_norm
          auto dim = readIntArrayRef("dim");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::frobenius_norm(self, dim, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 595: { // frobenius_norm
          auto dim = readIntArrayRef("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::frobenius_norm(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 596: { // nuclear_norm
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::nuclear_norm(self, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 597: { // nuclear_norm
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::nuclear_norm(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 598: { // nuclear_norm
          auto dim = readIntArrayRef("dim");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::nuclear_norm(self, dim, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 599: { // nuclear_norm
          auto dim = readIntArrayRef("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::nuclear_norm(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 600: { // clone
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::clone(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 601: { // pow
          at::Scalar exponent = readScalarAttribute("exponent");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::pow(self, exponent);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 602: { // sub
          at::Scalar alpha = readScalarAttribute("alpha");
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::sub(self, other, alpha);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 603: { // sub
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::sub(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 604: { // sub
          at::Scalar other = readScalarAttribute("other");
          at::Scalar alpha = readScalarAttribute("alpha");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::sub(self, other, alpha);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 605: { // sub
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::sub(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 606: { // rsub
          at::Scalar alpha = readScalarAttribute("alpha");
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::rsub(self, other, alpha);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 607: { // rsub
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::rsub(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 608: { // rsub
          at::Scalar other = readScalarAttribute("other");
          at::Scalar alpha = readScalarAttribute("alpha");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::rsub(self, other, alpha);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 609: { // rsub
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::rsub(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 610: { // s_native_addmm
          at::Scalar beta = readScalarAttribute("beta");
          at::Scalar alpha = readScalarAttribute("alpha");
          run_op = [=] {
              auto self = peek(0, 3);
              auto mat1 = peek(1, 3);
              auto mat2 = peek(2, 3);
              auto the_result = at::s_native_addmm(self, mat1, mat2, beta, alpha);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 611: { // s_native_addmm
          at::Scalar beta = readScalarAttribute("beta");
          run_op = [=] {
              auto self = peek(0, 3);
              auto mat1 = peek(1, 3);
              auto mat2 = peek(2, 3);
              auto the_result = at::s_native_addmm(self, mat1, mat2, beta);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 612: { // s_native_addmm
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto mat1 = peek(1, 3);
              auto mat2 = peek(2, 3);
              auto the_result = at::s_native_addmm(self, mat1, mat2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 613: { // _sparse_addmm
          at::Scalar beta = readScalarAttribute("beta");
          at::Scalar alpha = readScalarAttribute("alpha");
          run_op = [=] {
              auto self = peek(0, 3);
              auto sparse = peek(1, 3);
              auto dense = peek(2, 3);
              auto the_result = at::_sparse_addmm(self, sparse, dense, beta, alpha);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 614: { // _sparse_addmm
          at::Scalar beta = readScalarAttribute("beta");
          run_op = [=] {
              auto self = peek(0, 3);
              auto sparse = peek(1, 3);
              auto dense = peek(2, 3);
              auto the_result = at::_sparse_addmm(self, sparse, dense, beta);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 615: { // _sparse_addmm
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto sparse = peek(1, 3);
              auto dense = peek(2, 3);
              auto the_result = at::_sparse_addmm(self, sparse, dense);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 616: { // addmm
          at::Scalar beta = readScalarAttribute("beta");
          at::Scalar alpha = readScalarAttribute("alpha");
          run_op = [=] {
              auto self = peek(0, 3);
              auto mat1 = peek(1, 3);
              auto mat2 = peek(2, 3);
              auto the_result = at::addmm(self, mat1, mat2, beta, alpha);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 617: { // addmm
          at::Scalar beta = readScalarAttribute("beta");
          run_op = [=] {
              auto self = peek(0, 3);
              auto mat1 = peek(1, 3);
              auto mat2 = peek(2, 3);
              auto the_result = at::addmm(self, mat1, mat2, beta);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 618: { // addmm
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto mat1 = peek(1, 3);
              auto mat2 = peek(2, 3);
              auto the_result = at::addmm(self, mat1, mat2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 619: { // sparse_mask
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto mask = peek(1, 2);
              auto the_result = self.sparse_mask(mask);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 620: { // to_dense
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self.to_dense();
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 621: { // to_dense_backward
      
          run_op = [=] {
              auto grad = peek(0, 2);
              auto input = peek(1, 2);
              auto the_result = at::to_dense_backward(grad, input);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 622: { // sparse_dim
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self.sparse_dim();
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 623: { // _dimI
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self._dimI();
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 624: { // dense_dim
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self.dense_dim();
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 625: { // _dimV
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self._dimV();
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 626: { // _nnz
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self._nnz();
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 627: { // coalesce
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self.coalesce();
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 628: { // is_coalesced
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self.is_coalesced();
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 629: { // _indices
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self._indices();
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 630: { // _values
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self._values();
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 631: { // indices
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self.indices();
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 632: { // values
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self.values();
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 633: { // hspmm
      
          run_op = [=] {
              auto mat1 = peek(0, 2);
              auto mat2 = peek(1, 2);
              auto the_result = at::hspmm(mat1, mat2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 634: { // numel
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::numel(self);
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 635: { // unbind
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::unbind(self, dim);
                if(OutputSize() > 0) {assignListStartingAt(0, the_result);}
              return true;
          };
      } break;
      case 636: { // unbind
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::unbind(self);
                if(OutputSize() > 0) {assignListStartingAt(0, the_result);}
              return true;
          };
      } break;
      case 637: { // to_sparse
          int64_t sparse_dim = readAttribute<int64_t>("sparse_dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self.to_sparse(sparse_dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 638: { // to_sparse
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self.to_sparse();
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 639: { // to_mkldnn
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self.to_mkldnn();
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 640: { // mkldnn_reorder_conv2d_weight
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::mkldnn_reorder_conv2d_weight(self, padding, stride, dilation, groups);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 641: { // mkldnn_reorder_conv2d_weight
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::mkldnn_reorder_conv2d_weight(self, padding, stride, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 642: { // mkldnn_reorder_conv2d_weight
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::mkldnn_reorder_conv2d_weight(self, padding, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 643: { // mkldnn_reorder_conv2d_weight
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::mkldnn_reorder_conv2d_weight(self, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 644: { // mkldnn_reorder_conv2d_weight
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::mkldnn_reorder_conv2d_weight(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 645: { // to_mkldnn_backward
      
          run_op = [=] {
              auto grad = peek(0, 2);
              auto input = peek(1, 2);
              auto the_result = at::to_mkldnn_backward(grad, input);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 646: { // dequantize
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::dequantize(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 647: { // q_zero_point
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::q_zero_point(self);
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 648: { // int_repr
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::int_repr(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 649: { // _per_tensor_affine_qtensor
          double scale = readAttribute<float>("scale");
          int64_t zero_point = readAttribute<int64_t>("zero_point");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_per_tensor_affine_qtensor(self, scale, zero_point);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 650: { // fake_quantize_per_tensor_affine
          double scale = readAttribute<float>("scale");
          int64_t zero_point = readAttribute<int64_t>("zero_point");
          int64_t quant_min = readAttribute<int64_t>("quant_min");
          int64_t quant_max = readAttribute<int64_t>("quant_max");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::fake_quantize_per_tensor_affine(self, scale, zero_point, quant_min, quant_max);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 651: { // fake_quantize_per_tensor_affine_backward
          double scale = readAttribute<float>("scale");
          int64_t zero_point = readAttribute<int64_t>("zero_point");
          int64_t quant_min = readAttribute<int64_t>("quant_min");
          int64_t quant_max = readAttribute<int64_t>("quant_max");
          run_op = [=] {
              auto grad = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::fake_quantize_per_tensor_affine_backward(grad, self, scale, zero_point, quant_min, quant_max);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 652: { // meshgrid
      
          run_op = [=] {
              auto tensors = peekSlice(0, InputSize() - 0, InputSize());
              auto the_result = at::meshgrid(tensors);
                if(OutputSize() > 0) {assignListStartingAt(0, the_result);}
              return true;
          };
      } break;
      case 653: { // cartesian_prod
      
          run_op = [=] {
              auto tensors = peekSlice(0, InputSize() - 0, InputSize());
              auto the_result = at::cartesian_prod(tensors);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 654: { // combinations
          int64_t r = readAttribute<int64_t>("r");
          bool with_replacement = readAttribute<int64_t>("with_replacement");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::combinations(self, r, with_replacement);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 655: { // combinations
          int64_t r = readAttribute<int64_t>("r");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::combinations(self, r);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 656: { // combinations
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::combinations(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 657: { // item
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self.item();
                if(OutputSize() > 0) {assignTo(Output(0),self.scalar_type(), the_result);}
              return true;
          };
      } break;
      case 658: { // _local_scalar_dense
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_local_scalar_dense(self);
                if(OutputSize() > 0) {assignTo(Output(0),self.scalar_type(), the_result);}
              return true;
          };
      } break;
      case 659: { // _thnn_fused_lstm_cell
      
          run_op = [=] {
              auto input_gates = peek(0, 5);
              auto hidden_gates = peek(1, 5);
              auto cx = peek(2, 5);
              auto input_bias = peek(3, 5);
              auto hidden_bias = peek(4, 5);
              auto the_result = at::_thnn_fused_lstm_cell(input_gates, hidden_gates, cx, input_bias, hidden_bias);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 660: { // _thnn_fused_lstm_cell
      
          run_op = [=] {
              auto input_gates = peek(0, 4);
              auto hidden_gates = peek(1, 4);
              auto cx = peek(2, 4);
              auto input_bias = peek(3, 4);
              auto the_result = at::_thnn_fused_lstm_cell(input_gates, hidden_gates, cx, input_bias);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 661: { // _thnn_fused_lstm_cell
      
          run_op = [=] {
              auto input_gates = peek(0, 3);
              auto hidden_gates = peek(1, 3);
              auto cx = peek(2, 3);
              auto the_result = at::_thnn_fused_lstm_cell(input_gates, hidden_gates, cx);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 662: { // _thnn_fused_lstm_cell_backward
          bool has_bias = readAttribute<int64_t>("has_bias");
          run_op = [=] {
              auto grad_hy = peek(0, 5);
              auto grad_cy = peek(1, 5);
              auto cx = peek(2, 5);
              auto cy = peek(3, 5);
              auto workspace = peek(4, 5);
              auto the_result = at::_thnn_fused_lstm_cell_backward(grad_hy, grad_cy, cx, cy, workspace, has_bias);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
                if(OutputSize() > 3) {assignTo(Output(3),std::get<3>(the_result));}
                if(OutputSize() > 4) {assignTo(Output(4),std::get<4>(the_result));}
              return true;
          };
      } break;
      case 663: { // _thnn_fused_gru_cell
      
          run_op = [=] {
              auto input_gates = peek(0, 5);
              auto hidden_gates = peek(1, 5);
              auto hx = peek(2, 5);
              auto input_bias = peek(3, 5);
              auto hidden_bias = peek(4, 5);
              auto the_result = at::_thnn_fused_gru_cell(input_gates, hidden_gates, hx, input_bias, hidden_bias);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 664: { // _thnn_fused_gru_cell
      
          run_op = [=] {
              auto input_gates = peek(0, 4);
              auto hidden_gates = peek(1, 4);
              auto hx = peek(2, 4);
              auto input_bias = peek(3, 4);
              auto the_result = at::_thnn_fused_gru_cell(input_gates, hidden_gates, hx, input_bias);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 665: { // _thnn_fused_gru_cell
      
          run_op = [=] {
              auto input_gates = peek(0, 3);
              auto hidden_gates = peek(1, 3);
              auto hx = peek(2, 3);
              auto the_result = at::_thnn_fused_gru_cell(input_gates, hidden_gates, hx);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 666: { // _thnn_fused_gru_cell_backward
          bool has_bias = readAttribute<int64_t>("has_bias");
          run_op = [=] {
              auto grad_hy = peek(0, 2);
              auto workspace = peek(1, 2);
              auto the_result = at::_thnn_fused_gru_cell_backward(grad_hy, workspace, has_bias);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
                if(OutputSize() > 3) {assignTo(Output(3),std::get<3>(the_result));}
                if(OutputSize() > 4) {assignTo(Output(4),std::get<4>(the_result));}
              return true;
          };
      } break;
      case 667: { // lstm
          bool has_biases = readAttribute<int64_t>("has_biases");
          int64_t num_layers = readAttribute<int64_t>("num_layers");
          double dropout = readAttribute<float>("dropout");
          bool train = readAttribute<int64_t>("train");
          bool bidirectional = readAttribute<int64_t>("bidirectional");
          bool batch_first = readAttribute<int64_t>("batch_first");
          run_op = [=] {
              auto input = peek(0, InputSize());
              auto hx = peekSlice(1, InputSize() - 1, InputSize());
              auto params = peekSlice(1, InputSize() - 1, InputSize());
              auto the_result = at::lstm(input, hx, params, has_biases, num_layers, dropout, train, bidirectional, batch_first);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 668: { // lstm
          bool has_biases = readAttribute<int64_t>("has_biases");
          int64_t num_layers = readAttribute<int64_t>("num_layers");
          double dropout = readAttribute<float>("dropout");
          bool train = readAttribute<int64_t>("train");
          bool bidirectional = readAttribute<int64_t>("bidirectional");
          run_op = [=] {
              auto data = peek(0, InputSize());
              auto batch_sizes = peek(1, InputSize());
              auto hx = peekSlice(2, InputSize() - 2, InputSize());
              auto params = peekSlice(2, InputSize() - 2, InputSize());
              auto the_result = at::lstm(data, batch_sizes, hx, params, has_biases, num_layers, dropout, train, bidirectional);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 669: { // gru
          bool has_biases = readAttribute<int64_t>("has_biases");
          int64_t num_layers = readAttribute<int64_t>("num_layers");
          double dropout = readAttribute<float>("dropout");
          bool train = readAttribute<int64_t>("train");
          bool bidirectional = readAttribute<int64_t>("bidirectional");
          bool batch_first = readAttribute<int64_t>("batch_first");
          run_op = [=] {
              auto input = peek(0, InputSize());
              auto hx = peek(1, InputSize());
              auto params = peekSlice(2, InputSize() - 2, InputSize());
              auto the_result = at::gru(input, hx, params, has_biases, num_layers, dropout, train, bidirectional, batch_first);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 670: { // gru
          bool has_biases = readAttribute<int64_t>("has_biases");
          int64_t num_layers = readAttribute<int64_t>("num_layers");
          double dropout = readAttribute<float>("dropout");
          bool train = readAttribute<int64_t>("train");
          bool bidirectional = readAttribute<int64_t>("bidirectional");
          run_op = [=] {
              auto data = peek(0, InputSize());
              auto batch_sizes = peek(1, InputSize());
              auto hx = peek(2, InputSize());
              auto params = peekSlice(3, InputSize() - 3, InputSize());
              auto the_result = at::gru(data, batch_sizes, hx, params, has_biases, num_layers, dropout, train, bidirectional);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 671: { // rnn_tanh
          bool has_biases = readAttribute<int64_t>("has_biases");
          int64_t num_layers = readAttribute<int64_t>("num_layers");
          double dropout = readAttribute<float>("dropout");
          bool train = readAttribute<int64_t>("train");
          bool bidirectional = readAttribute<int64_t>("bidirectional");
          bool batch_first = readAttribute<int64_t>("batch_first");
          run_op = [=] {
              auto input = peek(0, InputSize());
              auto hx = peek(1, InputSize());
              auto params = peekSlice(2, InputSize() - 2, InputSize());
              auto the_result = at::rnn_tanh(input, hx, params, has_biases, num_layers, dropout, train, bidirectional, batch_first);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 672: { // rnn_tanh
          bool has_biases = readAttribute<int64_t>("has_biases");
          int64_t num_layers = readAttribute<int64_t>("num_layers");
          double dropout = readAttribute<float>("dropout");
          bool train = readAttribute<int64_t>("train");
          bool bidirectional = readAttribute<int64_t>("bidirectional");
          run_op = [=] {
              auto data = peek(0, InputSize());
              auto batch_sizes = peek(1, InputSize());
              auto hx = peek(2, InputSize());
              auto params = peekSlice(3, InputSize() - 3, InputSize());
              auto the_result = at::rnn_tanh(data, batch_sizes, hx, params, has_biases, num_layers, dropout, train, bidirectional);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 673: { // rnn_relu
          bool has_biases = readAttribute<int64_t>("has_biases");
          int64_t num_layers = readAttribute<int64_t>("num_layers");
          double dropout = readAttribute<float>("dropout");
          bool train = readAttribute<int64_t>("train");
          bool bidirectional = readAttribute<int64_t>("bidirectional");
          bool batch_first = readAttribute<int64_t>("batch_first");
          run_op = [=] {
              auto input = peek(0, InputSize());
              auto hx = peek(1, InputSize());
              auto params = peekSlice(2, InputSize() - 2, InputSize());
              auto the_result = at::rnn_relu(input, hx, params, has_biases, num_layers, dropout, train, bidirectional, batch_first);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 674: { // rnn_relu
          bool has_biases = readAttribute<int64_t>("has_biases");
          int64_t num_layers = readAttribute<int64_t>("num_layers");
          double dropout = readAttribute<float>("dropout");
          bool train = readAttribute<int64_t>("train");
          bool bidirectional = readAttribute<int64_t>("bidirectional");
          run_op = [=] {
              auto data = peek(0, InputSize());
              auto batch_sizes = peek(1, InputSize());
              auto hx = peek(2, InputSize());
              auto params = peekSlice(3, InputSize() - 3, InputSize());
              auto the_result = at::rnn_relu(data, batch_sizes, hx, params, has_biases, num_layers, dropout, train, bidirectional);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 675: { // lstm_cell
      
          run_op = [=] {
              auto input = peek(0, InputSize());
              auto hx = peekSlice(1, InputSize() - 5, InputSize());
              auto w_ih = peek(1, 5);
              auto w_hh = peek(2, 5);
              auto b_ih = peek(3, 5);
              auto b_hh = peek(4, 5);
              auto the_result = at::lstm_cell(input, hx, w_ih, w_hh, b_ih, b_hh);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 676: { // gru_cell
      
          run_op = [=] {
              auto input = peek(0, 6);
              auto hx = peek(1, 6);
              auto w_ih = peek(2, 6);
              auto w_hh = peek(3, 6);
              auto b_ih = peek(4, 6);
              auto b_hh = peek(5, 6);
              auto the_result = at::gru_cell(input, hx, w_ih, w_hh, b_ih, b_hh);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 677: { // gru_cell
      
          run_op = [=] {
              auto input = peek(0, 5);
              auto hx = peek(1, 5);
              auto w_ih = peek(2, 5);
              auto w_hh = peek(3, 5);
              auto b_ih = peek(4, 5);
              auto the_result = at::gru_cell(input, hx, w_ih, w_hh, b_ih);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 678: { // gru_cell
      
          run_op = [=] {
              auto input = peek(0, 4);
              auto hx = peek(1, 4);
              auto w_ih = peek(2, 4);
              auto w_hh = peek(3, 4);
              auto the_result = at::gru_cell(input, hx, w_ih, w_hh);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 679: { // rnn_tanh_cell
      
          run_op = [=] {
              auto input = peek(0, 6);
              auto hx = peek(1, 6);
              auto w_ih = peek(2, 6);
              auto w_hh = peek(3, 6);
              auto b_ih = peek(4, 6);
              auto b_hh = peek(5, 6);
              auto the_result = at::rnn_tanh_cell(input, hx, w_ih, w_hh, b_ih, b_hh);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 680: { // rnn_tanh_cell
      
          run_op = [=] {
              auto input = peek(0, 5);
              auto hx = peek(1, 5);
              auto w_ih = peek(2, 5);
              auto w_hh = peek(3, 5);
              auto b_ih = peek(4, 5);
              auto the_result = at::rnn_tanh_cell(input, hx, w_ih, w_hh, b_ih);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 681: { // rnn_tanh_cell
      
          run_op = [=] {
              auto input = peek(0, 4);
              auto hx = peek(1, 4);
              auto w_ih = peek(2, 4);
              auto w_hh = peek(3, 4);
              auto the_result = at::rnn_tanh_cell(input, hx, w_ih, w_hh);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 682: { // rnn_relu_cell
      
          run_op = [=] {
              auto input = peek(0, 6);
              auto hx = peek(1, 6);
              auto w_ih = peek(2, 6);
              auto w_hh = peek(3, 6);
              auto b_ih = peek(4, 6);
              auto b_hh = peek(5, 6);
              auto the_result = at::rnn_relu_cell(input, hx, w_ih, w_hh, b_ih, b_hh);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 683: { // rnn_relu_cell
      
          run_op = [=] {
              auto input = peek(0, 5);
              auto hx = peek(1, 5);
              auto w_ih = peek(2, 5);
              auto w_hh = peek(3, 5);
              auto b_ih = peek(4, 5);
              auto the_result = at::rnn_relu_cell(input, hx, w_ih, w_hh, b_ih);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 684: { // rnn_relu_cell
      
          run_op = [=] {
              auto input = peek(0, 4);
              auto hx = peek(1, 4);
              auto w_ih = peek(2, 4);
              auto w_hh = peek(3, 4);
              auto the_result = at::rnn_relu_cell(input, hx, w_ih, w_hh);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 685: { // quantized_lstm
          bool has_biases = readAttribute<int64_t>("has_biases");
          int64_t num_layers = readAttribute<int64_t>("num_layers");
          double dropout = readAttribute<float>("dropout");
          bool train = readAttribute<int64_t>("train");
          bool bidirectional = readAttribute<int64_t>("bidirectional");
          bool batch_first = readAttribute<int64_t>("batch_first");
          run_op = [=] {
              auto input = peek(0, InputSize());
              auto hx = peekSlice(1, InputSize() - 1, InputSize());
              auto params = peekSlice(1, InputSize() - 1, InputSize());
              auto the_result = at::quantized_lstm(input, hx, params, has_biases, num_layers, dropout, train, bidirectional, batch_first);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 686: { // quantized_gru
          bool has_biases = readAttribute<int64_t>("has_biases");
          int64_t num_layers = readAttribute<int64_t>("num_layers");
          double dropout = readAttribute<float>("dropout");
          bool train = readAttribute<int64_t>("train");
          bool bidirectional = readAttribute<int64_t>("bidirectional");
          bool batch_first = readAttribute<int64_t>("batch_first");
          run_op = [=] {
              auto input = peek(0, InputSize());
              auto hx = peek(1, InputSize());
              auto params = peekSlice(2, InputSize() - 2, InputSize());
              auto the_result = at::quantized_gru(input, hx, params, has_biases, num_layers, dropout, train, bidirectional, batch_first);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 687: { // quantized_gru
          bool has_biases = readAttribute<int64_t>("has_biases");
          int64_t num_layers = readAttribute<int64_t>("num_layers");
          double dropout = readAttribute<float>("dropout");
          bool train = readAttribute<int64_t>("train");
          bool bidirectional = readAttribute<int64_t>("bidirectional");
          run_op = [=] {
              auto data = peek(0, InputSize());
              auto batch_sizes = peek(1, InputSize());
              auto hx = peek(2, InputSize());
              auto params = peekSlice(3, InputSize() - 3, InputSize());
              auto the_result = at::quantized_gru(data, batch_sizes, hx, params, has_biases, num_layers, dropout, train, bidirectional);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 688: { // quantized_lstm_cell
          at::Scalar scale_ih = readScalarAttribute("scale_ih");
          at::Scalar scale_hh = readScalarAttribute("scale_hh");
          at::Scalar zero_point_ih = readScalarAttribute("zero_point_ih");
          at::Scalar zero_point_hh = readScalarAttribute("zero_point_hh");
          run_op = [=] {
              auto input = peek(0, InputSize());
              auto hx = peekSlice(1, InputSize() - 9, InputSize());
              auto w_ih = peek(1, 9);
              auto w_hh = peek(2, 9);
              auto b_ih = peek(3, 9);
              auto b_hh = peek(4, 9);
              auto packed_ih = peek(5, 9);
              auto packed_hh = peek(6, 9);
              auto col_offsets_ih = peek(7, 9);
              auto col_offsets_hh = peek(8, 9);
              auto the_result = at::quantized_lstm_cell(input, hx, w_ih, w_hh, b_ih, b_hh, packed_ih, packed_hh, col_offsets_ih, col_offsets_hh, scale_ih, scale_hh, zero_point_ih, zero_point_hh);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 689: { // quantized_gru_cell
          at::Scalar scale_ih = readScalarAttribute("scale_ih");
          at::Scalar scale_hh = readScalarAttribute("scale_hh");
          at::Scalar zero_point_ih = readScalarAttribute("zero_point_ih");
          at::Scalar zero_point_hh = readScalarAttribute("zero_point_hh");
          run_op = [=] {
              auto input = peek(0, 10);
              auto hx = peek(1, 10);
              auto w_ih = peek(2, 10);
              auto w_hh = peek(3, 10);
              auto b_ih = peek(4, 10);
              auto b_hh = peek(5, 10);
              auto packed_ih = peek(6, 10);
              auto packed_hh = peek(7, 10);
              auto col_offsets_ih = peek(8, 10);
              auto col_offsets_hh = peek(9, 10);
              auto the_result = at::quantized_gru_cell(input, hx, w_ih, w_hh, b_ih, b_hh, packed_ih, packed_hh, col_offsets_ih, col_offsets_hh, scale_ih, scale_hh, zero_point_ih, zero_point_hh);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 690: { // quantized_rnn_relu_cell
          at::Scalar scale_ih = readScalarAttribute("scale_ih");
          at::Scalar scale_hh = readScalarAttribute("scale_hh");
          at::Scalar zero_point_ih = readScalarAttribute("zero_point_ih");
          at::Scalar zero_point_hh = readScalarAttribute("zero_point_hh");
          run_op = [=] {
              auto input = peek(0, 10);
              auto hx = peek(1, 10);
              auto w_ih = peek(2, 10);
              auto w_hh = peek(3, 10);
              auto b_ih = peek(4, 10);
              auto b_hh = peek(5, 10);
              auto packed_ih = peek(6, 10);
              auto packed_hh = peek(7, 10);
              auto col_offsets_ih = peek(8, 10);
              auto col_offsets_hh = peek(9, 10);
              auto the_result = at::quantized_rnn_relu_cell(input, hx, w_ih, w_hh, b_ih, b_hh, packed_ih, packed_hh, col_offsets_ih, col_offsets_hh, scale_ih, scale_hh, zero_point_ih, zero_point_hh);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 691: { // quantized_rnn_tanh_cell
          at::Scalar scale_ih = readScalarAttribute("scale_ih");
          at::Scalar scale_hh = readScalarAttribute("scale_hh");
          at::Scalar zero_point_ih = readScalarAttribute("zero_point_ih");
          at::Scalar zero_point_hh = readScalarAttribute("zero_point_hh");
          run_op = [=] {
              auto input = peek(0, 10);
              auto hx = peek(1, 10);
              auto w_ih = peek(2, 10);
              auto w_hh = peek(3, 10);
              auto b_ih = peek(4, 10);
              auto b_hh = peek(5, 10);
              auto packed_ih = peek(6, 10);
              auto packed_hh = peek(7, 10);
              auto col_offsets_ih = peek(8, 10);
              auto col_offsets_hh = peek(9, 10);
              auto the_result = at::quantized_rnn_tanh_cell(input, hx, w_ih, w_hh, b_ih, b_hh, packed_ih, packed_hh, col_offsets_ih, col_offsets_hh, scale_ih, scale_hh, zero_point_ih, zero_point_hh);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 692: { // _pack_padded_sequence
          bool batch_first = readAttribute<int64_t>("batch_first");
          run_op = [=] {
              auto input = peek(0, 2);
              auto lengths = peek(1, 2);
              auto the_result = at::_pack_padded_sequence(input, lengths, batch_first);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 693: { // _pack_padded_sequence_backward
          auto input_size = readIntArrayRef("input_size");
          bool batch_first = readAttribute<int64_t>("batch_first");
          run_op = [=] {
              auto grad = peek(0, 2);
              auto batch_sizes = peek(1, 2);
              auto the_result = at::_pack_padded_sequence_backward(grad, input_size, batch_sizes, batch_first);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 694: { // _pad_packed_sequence
          bool batch_first = readAttribute<int64_t>("batch_first");
          at::Scalar padding_value = readScalarAttribute("padding_value");
          int64_t total_length = readAttribute<int64_t>("total_length");
          run_op = [=] {
              auto data = peek(0, 2);
              auto batch_sizes = peek(1, 2);
              auto the_result = at::_pad_packed_sequence(data, batch_sizes, batch_first, padding_value, total_length);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 695: { // is_set_to
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto tensor = peek(1, 2);
              auto the_result = self.is_set_to(tensor);
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 696: { // masked_fill
          at::Scalar value = readScalarAttribute("value");
          run_op = [=] {
              auto self = peek(0, 2);
              auto mask = peek(1, 2);
              auto the_result = at::masked_fill(self, mask, value);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 697: { // masked_fill
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto mask = peek(1, 3);
              auto value = peek(2, 3);
              auto the_result = at::masked_fill(self, mask, value);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 698: { // masked_scatter
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto mask = peek(1, 3);
              auto source = peek(2, 3);
              auto the_result = at::masked_scatter(self, mask, source);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 699: { // view
          auto size = readIntArrayRef("size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self.view(size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 700: { // index_add
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 3);
              auto index = peek(1, 3);
              auto source = peek(2, 3);
              auto the_result = at::index_add(self, dim, index, source);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 701: { // index_fill
          int64_t dim = readAttribute<int64_t>("dim");
          at::Scalar value = readScalarAttribute("value");
          run_op = [=] {
              auto self = peek(0, 2);
              auto index = peek(1, 2);
              auto the_result = at::index_fill(self, dim, index, value);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 702: { // index_fill
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 3);
              auto index = peek(1, 3);
              auto value = peek(2, 3);
              auto the_result = at::index_fill(self, dim, index, value);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 703: { // scatter
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 3);
              auto index = peek(1, 3);
              auto src = peek(2, 3);
              auto the_result = at::scatter(self, dim, index, src);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 704: { // scatter
          int64_t dim = readAttribute<int64_t>("dim");
          at::Scalar value = readScalarAttribute("value");
          run_op = [=] {
              auto self = peek(0, 2);
              auto index = peek(1, 2);
              auto the_result = at::scatter(self, dim, index, value);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 705: { // scatter_add
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 3);
              auto index = peek(1, 3);
              auto src = peek(2, 3);
              auto the_result = at::scatter_add(self, dim, index, src);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 706: { // __and__
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::__and__(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 707: { // __and__
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::__and__(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 708: { // __or__
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::__or__(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 709: { // __or__
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::__or__(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 710: { // __xor__
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::__xor__(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 711: { // __xor__
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::__xor__(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 712: { // __lshift__
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::__lshift__(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 713: { // __lshift__
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::__lshift__(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 714: { // __rshift__
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::__rshift__(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 715: { // __rshift__
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::__rshift__(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 716: { // addbmm
          at::Scalar beta = readScalarAttribute("beta");
          at::Scalar alpha = readScalarAttribute("alpha");
          run_op = [=] {
              auto self = peek(0, 3);
              auto batch1 = peek(1, 3);
              auto batch2 = peek(2, 3);
              auto the_result = at::addbmm(self, batch1, batch2, beta, alpha);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 717: { // addbmm
          at::Scalar beta = readScalarAttribute("beta");
          run_op = [=] {
              auto self = peek(0, 3);
              auto batch1 = peek(1, 3);
              auto batch2 = peek(2, 3);
              auto the_result = at::addbmm(self, batch1, batch2, beta);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 718: { // addbmm
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto batch1 = peek(1, 3);
              auto batch2 = peek(2, 3);
              auto the_result = at::addbmm(self, batch1, batch2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 719: { // diag
          int64_t diagonal = readAttribute<int64_t>("diagonal");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::diag(self, diagonal);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 720: { // diag
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::diag(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 721: { // cross
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::cross(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 722: { // triu
          int64_t diagonal = readAttribute<int64_t>("diagonal");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::triu(self, diagonal);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 723: { // triu
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::triu(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 724: { // tril
          int64_t diagonal = readAttribute<int64_t>("diagonal");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::tril(self, diagonal);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 725: { // tril
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::tril(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 726: { // trace
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::trace(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 727: { // ne
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::ne(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 728: { // ne
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::ne(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 729: { // eq
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::eq(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 730: { // eq
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::eq(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 731: { // ge
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::ge(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 732: { // ge
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::ge(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 733: { // le
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::le(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 734: { // le
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::le(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 735: { // gt
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::gt(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 736: { // gt
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::gt(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 737: { // lt
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::lt(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 738: { // lt
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::lt(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 739: { // take
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto index = peek(1, 2);
              auto the_result = at::take(self, index);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 740: { // index_select
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 2);
              auto index = peek(1, 2);
              auto the_result = at::index_select(self, dim, index);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 741: { // masked_select
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto mask = peek(1, 2);
              auto the_result = at::masked_select(self, mask);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 742: { // nonzero
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::nonzero(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 743: { // nonzero_numpy
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::nonzero_numpy(self);
                if(OutputSize() > 0) {assignListStartingAt(0, the_result);}
              return true;
          };
      } break;
      case 744: { // gather
          int64_t dim = readAttribute<int64_t>("dim");
          bool sparse_grad = readAttribute<int64_t>("sparse_grad");
          run_op = [=] {
              auto self = peek(0, 2);
              auto index = peek(1, 2);
              auto the_result = at::gather(self, dim, index, sparse_grad);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 745: { // gather
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 2);
              auto index = peek(1, 2);
              auto the_result = at::gather(self, dim, index);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 746: { // _gather_sparse_backward
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 3);
              auto index = peek(1, 3);
              auto grad = peek(2, 3);
              auto the_result = at::_gather_sparse_backward(self, dim, index, grad);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 747: { // addcmul
          at::Scalar value = readScalarAttribute("value");
          run_op = [=] {
              auto self = peek(0, 3);
              auto tensor1 = peek(1, 3);
              auto tensor2 = peek(2, 3);
              auto the_result = at::addcmul(self, tensor1, tensor2, value);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 748: { // addcmul
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto tensor1 = peek(1, 3);
              auto tensor2 = peek(2, 3);
              auto the_result = at::addcmul(self, tensor1, tensor2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 749: { // addcdiv
          at::Scalar value = readScalarAttribute("value");
          run_op = [=] {
              auto self = peek(0, 3);
              auto tensor1 = peek(1, 3);
              auto tensor2 = peek(2, 3);
              auto the_result = at::addcdiv(self, tensor1, tensor2, value);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 750: { // addcdiv
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto tensor1 = peek(1, 3);
              auto tensor2 = peek(2, 3);
              auto the_result = at::addcdiv(self, tensor1, tensor2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 751: { // lstsq
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto A = peek(1, 2);
              auto the_result = at::lstsq(self, A);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 752: { // triangular_solve
          bool upper = readAttribute<int64_t>("upper");
          bool transpose = readAttribute<int64_t>("transpose");
          bool unitriangular = readAttribute<int64_t>("unitriangular");
          run_op = [=] {
              auto self = peek(0, 2);
              auto A = peek(1, 2);
              auto the_result = at::triangular_solve(self, A, upper, transpose, unitriangular);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 753: { // triangular_solve
          bool upper = readAttribute<int64_t>("upper");
          bool transpose = readAttribute<int64_t>("transpose");
          run_op = [=] {
              auto self = peek(0, 2);
              auto A = peek(1, 2);
              auto the_result = at::triangular_solve(self, A, upper, transpose);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 754: { // triangular_solve
          bool upper = readAttribute<int64_t>("upper");
          run_op = [=] {
              auto self = peek(0, 2);
              auto A = peek(1, 2);
              auto the_result = at::triangular_solve(self, A, upper);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 755: { // triangular_solve
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto A = peek(1, 2);
              auto the_result = at::triangular_solve(self, A);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 756: { // _triangular_solve_helper
          bool upper = readAttribute<int64_t>("upper");
          bool transpose = readAttribute<int64_t>("transpose");
          bool unitriangular = readAttribute<int64_t>("unitriangular");
          run_op = [=] {
              auto self = peek(0, 2);
              auto A = peek(1, 2);
              auto the_result = at::_triangular_solve_helper(self, A, upper, transpose, unitriangular);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 757: { // symeig
          bool eigenvectors = readAttribute<int64_t>("eigenvectors");
          bool upper = readAttribute<int64_t>("upper");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::symeig(self, eigenvectors, upper);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 758: { // symeig
          bool eigenvectors = readAttribute<int64_t>("eigenvectors");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::symeig(self, eigenvectors);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 759: { // symeig
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::symeig(self);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 760: { // _symeig_helper
          bool eigenvectors = readAttribute<int64_t>("eigenvectors");
          bool upper = readAttribute<int64_t>("upper");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_symeig_helper(self, eigenvectors, upper);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 761: { // eig
          bool eigenvectors = readAttribute<int64_t>("eigenvectors");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::eig(self, eigenvectors);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 762: { // eig
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::eig(self);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 763: { // svd
          bool some = readAttribute<int64_t>("some");
          bool compute_uv = readAttribute<int64_t>("compute_uv");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::svd(self, some, compute_uv);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 764: { // svd
          bool some = readAttribute<int64_t>("some");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::svd(self, some);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 765: { // svd
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::svd(self);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 766: { // _svd_helper
          bool some = readAttribute<int64_t>("some");
          bool compute_uv = readAttribute<int64_t>("compute_uv");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_svd_helper(self, some, compute_uv);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 767: { // cholesky
          bool upper = readAttribute<int64_t>("upper");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::cholesky(self, upper);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 768: { // cholesky
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::cholesky(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 769: { // _cholesky_helper
          bool upper = readAttribute<int64_t>("upper");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_cholesky_helper(self, upper);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 770: { // cholesky_solve
          bool upper = readAttribute<int64_t>("upper");
          run_op = [=] {
              auto self = peek(0, 2);
              auto input2 = peek(1, 2);
              auto the_result = at::cholesky_solve(self, input2, upper);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 771: { // cholesky_solve
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto input2 = peek(1, 2);
              auto the_result = at::cholesky_solve(self, input2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 772: { // _cholesky_solve_helper
          bool upper = readAttribute<int64_t>("upper");
          run_op = [=] {
              auto self = peek(0, 2);
              auto A = peek(1, 2);
              auto the_result = at::_cholesky_solve_helper(self, A, upper);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 773: { // solve
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto A = peek(1, 2);
              auto the_result = at::solve(self, A);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 774: { // _solve_helper
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto A = peek(1, 2);
              auto the_result = at::_solve_helper(self, A);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 775: { // cholesky_inverse
          bool upper = readAttribute<int64_t>("upper");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::cholesky_inverse(self, upper);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 776: { // cholesky_inverse
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::cholesky_inverse(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 777: { // qr
          bool some = readAttribute<int64_t>("some");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::qr(self, some);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 778: { // qr
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::qr(self);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 779: { // _qr_helper
          bool some = readAttribute<int64_t>("some");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_qr_helper(self, some);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 780: { // geqrf
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::geqrf(self);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 781: { // orgqr
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto input2 = peek(1, 2);
              auto the_result = at::orgqr(self, input2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 782: { // ormqr
          bool left = readAttribute<int64_t>("left");
          bool transpose = readAttribute<int64_t>("transpose");
          run_op = [=] {
              auto self = peek(0, 3);
              auto input2 = peek(1, 3);
              auto input3 = peek(2, 3);
              auto the_result = at::ormqr(self, input2, input3, left, transpose);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 783: { // ormqr
          bool left = readAttribute<int64_t>("left");
          run_op = [=] {
              auto self = peek(0, 3);
              auto input2 = peek(1, 3);
              auto input3 = peek(2, 3);
              auto the_result = at::ormqr(self, input2, input3, left);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 784: { // ormqr
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto input2 = peek(1, 3);
              auto input3 = peek(2, 3);
              auto the_result = at::ormqr(self, input2, input3);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 785: { // _lu_with_info
          bool pivot = readAttribute<int64_t>("pivot");
          bool check_errors = readAttribute<int64_t>("check_errors");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_lu_with_info(self, pivot, check_errors);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 786: { // _lu_with_info
          bool pivot = readAttribute<int64_t>("pivot");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_lu_with_info(self, pivot);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 787: { // _lu_with_info
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_lu_with_info(self);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 788: { // lu_solve
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto LU_data = peek(1, 3);
              auto LU_pivots = peek(2, 3);
              auto the_result = at::lu_solve(self, LU_data, LU_pivots);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 789: { // _lu_solve_helper
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto LU_data = peek(1, 3);
              auto LU_pivots = peek(2, 3);
              auto the_result = at::_lu_solve_helper(self, LU_data, LU_pivots);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 790: { // multinomial
          int64_t num_samples = readAttribute<int64_t>("num_samples");
          bool replacement = readAttribute<int64_t>("replacement");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::multinomial(self, num_samples, replacement);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 791: { // multinomial
          int64_t num_samples = readAttribute<int64_t>("num_samples");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::multinomial(self, num_samples);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 792: { // _multinomial_alias_setup
      
          run_op = [=] {
              auto probs = peek(0, 1);
              auto the_result = at::_multinomial_alias_setup(probs);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 793: { // _multinomial_alias_draw
          int64_t num_samples = readAttribute<int64_t>("num_samples");
          run_op = [=] {
              auto J = peek(0, 2);
              auto q = peek(1, 2);
              auto the_result = at::_multinomial_alias_draw(J, q, num_samples);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 794: { // lgamma
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::lgamma(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 795: { // digamma
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::digamma(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 796: { // polygamma
          int64_t n = readAttribute<int64_t>("n");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::polygamma(n, self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 797: { // erfinv
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::erfinv(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 798: { // dist
          at::Scalar p = readScalarAttribute("p");
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::dist(self, other, p);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 799: { // dist
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::dist(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 800: { // atan2
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::atan2(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 801: { // lerp
          at::Scalar weight = readScalarAttribute("weight");
          run_op = [=] {
              auto self = peek(0, 2);
              auto end = peek(1, 2);
              auto the_result = at::lerp(self, end, weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 802: { // lerp
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto end = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::lerp(self, end, weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 803: { // histc
          int64_t bins = readAttribute<int64_t>("bins");
          at::Scalar min = readScalarAttribute("min");
          at::Scalar max = readScalarAttribute("max");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::histc(self, bins, min, max);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 804: { // histc
          int64_t bins = readAttribute<int64_t>("bins");
          at::Scalar min = readScalarAttribute("min");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::histc(self, bins, min);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 805: { // histc
          int64_t bins = readAttribute<int64_t>("bins");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::histc(self, bins);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 806: { // histc
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::histc(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 807: { // sign
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::sign(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 808: { // fmod
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::fmod(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 809: { // fmod
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::fmod(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 810: { // remainder
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::remainder(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 811: { // remainder
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::remainder(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 812: { // min
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::min(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 813: { // min
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::min(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 814: { // max
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::max(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 815: { // max
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 816: { // median
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::median(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 817: { // sort
          int64_t dim = readAttribute<int64_t>("dim");
          bool descending = readAttribute<int64_t>("descending");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::sort(self, dim, descending);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 818: { // sort
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::sort(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 819: { // sort
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::sort(self);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 820: { // argsort
          int64_t dim = readAttribute<int64_t>("dim");
          bool descending = readAttribute<int64_t>("descending");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::argsort(self, dim, descending);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 821: { // argsort
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::argsort(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 822: { // argsort
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::argsort(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 823: { // topk
          int64_t k = readAttribute<int64_t>("k");
          int64_t dim = readAttribute<int64_t>("dim");
          bool largest = readAttribute<int64_t>("largest");
          bool sorted = readAttribute<int64_t>("sorted");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::topk(self, k, dim, largest, sorted);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 824: { // topk
          int64_t k = readAttribute<int64_t>("k");
          int64_t dim = readAttribute<int64_t>("dim");
          bool largest = readAttribute<int64_t>("largest");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::topk(self, k, dim, largest);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 825: { // topk
          int64_t k = readAttribute<int64_t>("k");
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::topk(self, k, dim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 826: { // topk
          int64_t k = readAttribute<int64_t>("k");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::topk(self, k);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 827: { // all
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::all(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 828: { // any
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::any(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 829: { // renorm
          at::Scalar p = readScalarAttribute("p");
          int64_t dim = readAttribute<int64_t>("dim");
          at::Scalar maxnorm = readScalarAttribute("maxnorm");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::renorm(self, p, dim, maxnorm);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 830: { // unfold
          int64_t dimension = readAttribute<int64_t>("dimension");
          int64_t size = readAttribute<int64_t>("size");
          int64_t step = readAttribute<int64_t>("step");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self.unfold(dimension, size, step);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 831: { // equal
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::equal(self, other);
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 832: { // pow
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto exponent = peek(1, 2);
              auto the_result = at::pow(self, exponent);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 833: { // pow
          at::Scalar self = readScalarAttribute("self");
          run_op = [=] {
              auto exponent = peek(0, 1);
              auto the_result = at::pow(self, exponent);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 834: { // alias
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::alias(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 835: { // _addr
          at::Scalar beta = readScalarAttribute("beta");
          at::Scalar alpha = readScalarAttribute("alpha");
          run_op = [=] {
              auto self = peek(0, 3);
              auto vec1 = peek(1, 3);
              auto vec2 = peek(2, 3);
              auto the_result = at::_addr(self, vec1, vec2, beta, alpha);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 836: { // _addr
          at::Scalar beta = readScalarAttribute("beta");
          run_op = [=] {
              auto self = peek(0, 3);
              auto vec1 = peek(1, 3);
              auto vec2 = peek(2, 3);
              auto the_result = at::_addr(self, vec1, vec2, beta);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 837: { // _addr
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto vec1 = peek(1, 3);
              auto vec2 = peek(2, 3);
              auto the_result = at::_addr(self, vec1, vec2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 838: { // _cumsum
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_cumsum(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 839: { // _cumprod
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_cumprod(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 840: { // _var
          bool unbiased = readAttribute<int64_t>("unbiased");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_var(self, unbiased);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 841: { // _var
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_var(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 842: { // _std
          bool unbiased = readAttribute<int64_t>("unbiased");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_std(self, unbiased);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 843: { // _std
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_std(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 844: { // _addmm
          at::Scalar beta = readScalarAttribute("beta");
          at::Scalar alpha = readScalarAttribute("alpha");
          run_op = [=] {
              auto self = peek(0, 3);
              auto mat1 = peek(1, 3);
              auto mat2 = peek(2, 3);
              auto the_result = at::_addmm(self, mat1, mat2, beta, alpha);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 845: { // _addmm
          at::Scalar beta = readScalarAttribute("beta");
          run_op = [=] {
              auto self = peek(0, 3);
              auto mat1 = peek(1, 3);
              auto mat2 = peek(2, 3);
              auto the_result = at::_addmm(self, mat1, mat2, beta);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 846: { // _addmm
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto mat1 = peek(1, 3);
              auto mat2 = peek(2, 3);
              auto the_result = at::_addmm(self, mat1, mat2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 847: { // _cat
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto tensors = peekSlice(0, InputSize() - 0, InputSize());
              auto the_result = at::_cat(tensors, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 848: { // _cat
      
          run_op = [=] {
              auto tensors = peekSlice(0, InputSize() - 0, InputSize());
              auto the_result = at::_cat(tensors);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 849: { // _mode
          int64_t dim = readAttribute<int64_t>("dim");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_mode(self, dim, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 850: { // _mode
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_mode(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 851: { // _mode
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_mode(self);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 852: { // _max
          int64_t dim = readAttribute<int64_t>("dim");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_max(self, dim, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 853: { // _max
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_max(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 854: { // _min
          int64_t dim = readAttribute<int64_t>("dim");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_min(self, dim, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 855: { // _min
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_min(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 856: { // binary_cross_entropy
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto self = peek(0, 3);
              auto target = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::binary_cross_entropy(self, target, weight, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 857: { // binary_cross_entropy
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto target = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::binary_cross_entropy(self, target, weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 858: { // binary_cross_entropy
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::binary_cross_entropy(self, target);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 859: { // binary_cross_entropy_backward
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto grad_output = peek(0, 4);
              auto self = peek(1, 4);
              auto target = peek(2, 4);
              auto weight = peek(3, 4);
              auto the_result = at::binary_cross_entropy_backward(grad_output, self, target, weight, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 860: { // binary_cross_entropy_backward
      
          run_op = [=] {
              auto grad_output = peek(0, 4);
              auto self = peek(1, 4);
              auto target = peek(2, 4);
              auto weight = peek(3, 4);
              auto the_result = at::binary_cross_entropy_backward(grad_output, self, target, weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 861: { // binary_cross_entropy_backward
      
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto target = peek(2, 3);
              auto the_result = at::binary_cross_entropy_backward(grad_output, self, target);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 862: { // mse_loss
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::mse_loss(self, target, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 863: { // mse_loss
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::mse_loss(self, target);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 864: { // mse_loss_backward
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto target = peek(2, 3);
              auto the_result = at::mse_loss_backward(grad_output, self, target, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 865: { // l1_loss
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::l1_loss(self, target, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 866: { // l1_loss
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::l1_loss(self, target);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 867: { // l1_loss_backward
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto target = peek(2, 3);
              auto the_result = at::l1_loss_backward(grad_output, self, target, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 868: { // multi_margin_loss
          at::Scalar p = readScalarAttribute("p");
          at::Scalar margin = readScalarAttribute("margin");
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto self = peek(0, 3);
              auto target = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::multi_margin_loss(self, target, p, margin, weight, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 869: { // multi_margin_loss
          at::Scalar p = readScalarAttribute("p");
          at::Scalar margin = readScalarAttribute("margin");
          run_op = [=] {
              auto self = peek(0, 3);
              auto target = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::multi_margin_loss(self, target, p, margin, weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 870: { // multi_margin_loss
          at::Scalar p = readScalarAttribute("p");
          at::Scalar margin = readScalarAttribute("margin");
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::multi_margin_loss(self, target, p, margin);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 871: { // multi_margin_loss
          at::Scalar p = readScalarAttribute("p");
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::multi_margin_loss(self, target, p);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 872: { // multi_margin_loss
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::multi_margin_loss(self, target);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 873: { // multi_margin_loss_backward
          at::Scalar p = readScalarAttribute("p");
          at::Scalar margin = readScalarAttribute("margin");
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto grad_output = peek(0, 4);
              auto self = peek(1, 4);
              auto target = peek(2, 4);
              auto weight = peek(3, 4);
              auto the_result = at::multi_margin_loss_backward(grad_output, self, target, p, margin, weight, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 874: { // multi_margin_loss_backward
          at::Scalar p = readScalarAttribute("p");
          at::Scalar margin = readScalarAttribute("margin");
          run_op = [=] {
              auto grad_output = peek(0, 4);
              auto self = peek(1, 4);
              auto target = peek(2, 4);
              auto weight = peek(3, 4);
              auto the_result = at::multi_margin_loss_backward(grad_output, self, target, p, margin, weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 875: { // multi_margin_loss_backward
          at::Scalar p = readScalarAttribute("p");
          at::Scalar margin = readScalarAttribute("margin");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto target = peek(2, 3);
              auto the_result = at::multi_margin_loss_backward(grad_output, self, target, p, margin);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 876: { // multilabel_margin_loss
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::multilabel_margin_loss(self, target, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 877: { // multilabel_margin_loss
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::multilabel_margin_loss(self, target);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 878: { // multilabel_margin_loss_forward
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::multilabel_margin_loss_forward(self, target, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 879: { // multilabel_margin_loss_backward
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto grad_output = peek(0, 4);
              auto self = peek(1, 4);
              auto target = peek(2, 4);
              auto is_target = peek(3, 4);
              auto the_result = at::multilabel_margin_loss_backward(grad_output, self, target, reduction, is_target);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 880: { // nll_loss
          int64_t reduction = readAttribute<int64_t>("reduction");
          int64_t ignore_index = readAttribute<int64_t>("ignore_index");
          run_op = [=] {
              auto self = peek(0, 3);
              auto target = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::nll_loss(self, target, weight, reduction, ignore_index);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 881: { // nll_loss
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto self = peek(0, 3);
              auto target = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::nll_loss(self, target, weight, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 882: { // nll_loss
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto target = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::nll_loss(self, target, weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 883: { // nll_loss
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::nll_loss(self, target);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 884: { // nll_loss_forward
          int64_t reduction = readAttribute<int64_t>("reduction");
          int64_t ignore_index = readAttribute<int64_t>("ignore_index");
          run_op = [=] {
              auto self = peek(0, 3);
              auto target = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::nll_loss_forward(self, target, weight, reduction, ignore_index);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 885: { // nll_loss_backward
          int64_t reduction = readAttribute<int64_t>("reduction");
          int64_t ignore_index = readAttribute<int64_t>("ignore_index");
          run_op = [=] {
              auto grad_output = peek(0, 5);
              auto self = peek(1, 5);
              auto target = peek(2, 5);
              auto weight = peek(3, 5);
              auto total_weight = peek(4, 5);
              auto the_result = at::nll_loss_backward(grad_output, self, target, weight, reduction, ignore_index, total_weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 886: { // nll_loss2d
          int64_t reduction = readAttribute<int64_t>("reduction");
          int64_t ignore_index = readAttribute<int64_t>("ignore_index");
          run_op = [=] {
              auto self = peek(0, 3);
              auto target = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::nll_loss2d(self, target, weight, reduction, ignore_index);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 887: { // nll_loss2d
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto self = peek(0, 3);
              auto target = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::nll_loss2d(self, target, weight, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 888: { // nll_loss2d
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto target = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::nll_loss2d(self, target, weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 889: { // nll_loss2d
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::nll_loss2d(self, target);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 890: { // nll_loss2d_forward
          int64_t reduction = readAttribute<int64_t>("reduction");
          int64_t ignore_index = readAttribute<int64_t>("ignore_index");
          run_op = [=] {
              auto self = peek(0, 3);
              auto target = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::nll_loss2d_forward(self, target, weight, reduction, ignore_index);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 891: { // nll_loss2d_backward
          int64_t reduction = readAttribute<int64_t>("reduction");
          int64_t ignore_index = readAttribute<int64_t>("ignore_index");
          run_op = [=] {
              auto grad_output = peek(0, 5);
              auto self = peek(1, 5);
              auto target = peek(2, 5);
              auto weight = peek(3, 5);
              auto total_weight = peek(4, 5);
              auto the_result = at::nll_loss2d_backward(grad_output, self, target, weight, reduction, ignore_index, total_weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 892: { // smooth_l1_loss
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::smooth_l1_loss(self, target, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 893: { // smooth_l1_loss
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::smooth_l1_loss(self, target);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 894: { // smooth_l1_loss_backward
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto target = peek(2, 3);
              auto the_result = at::smooth_l1_loss_backward(grad_output, self, target, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 895: { // soft_margin_loss
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::soft_margin_loss(self, target, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 896: { // soft_margin_loss
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::soft_margin_loss(self, target);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 897: { // soft_margin_loss_backward
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto target = peek(2, 3);
              auto the_result = at::soft_margin_loss_backward(grad_output, self, target, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 898: { // elu
          at::Scalar alpha = readScalarAttribute("alpha");
          at::Scalar scale = readScalarAttribute("scale");
          at::Scalar input_scale = readScalarAttribute("input_scale");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::elu(self, alpha, scale, input_scale);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 899: { // elu
          at::Scalar alpha = readScalarAttribute("alpha");
          at::Scalar scale = readScalarAttribute("scale");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::elu(self, alpha, scale);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 900: { // elu
          at::Scalar alpha = readScalarAttribute("alpha");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::elu(self, alpha);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 901: { // elu
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::elu(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 902: { // elu_backward
          at::Scalar alpha = readScalarAttribute("alpha");
          at::Scalar scale = readScalarAttribute("scale");
          at::Scalar input_scale = readScalarAttribute("input_scale");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto output = peek(1, 2);
              auto the_result = at::elu_backward(grad_output, alpha, scale, input_scale, output);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 903: { // glu
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::glu(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 904: { // glu
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::glu(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 905: { // glu_backward
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::glu_backward(grad_output, self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 906: { // hardtanh
          at::Scalar min_val = readScalarAttribute("min_val");
          at::Scalar max_val = readScalarAttribute("max_val");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::hardtanh(self, min_val, max_val);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 907: { // hardtanh
          at::Scalar min_val = readScalarAttribute("min_val");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::hardtanh(self, min_val);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 908: { // hardtanh
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::hardtanh(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 909: { // hardtanh_backward
          at::Scalar min_val = readScalarAttribute("min_val");
          at::Scalar max_val = readScalarAttribute("max_val");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::hardtanh_backward(grad_output, self, min_val, max_val);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 910: { // leaky_relu
          at::Scalar negative_slope = readScalarAttribute("negative_slope");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::leaky_relu(self, negative_slope);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 911: { // leaky_relu
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::leaky_relu(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 912: { // leaky_relu_backward
          at::Scalar negative_slope = readScalarAttribute("negative_slope");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::leaky_relu_backward(grad_output, self, negative_slope);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 913: { // log_sigmoid
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::log_sigmoid(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 914: { // log_sigmoid_forward
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::log_sigmoid_forward(self);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 915: { // log_sigmoid_backward
      
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto buffer = peek(2, 3);
              auto the_result = at::log_sigmoid_backward(grad_output, self, buffer);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 916: { // rrelu_with_noise
          at::Scalar lower = readScalarAttribute("lower");
          at::Scalar upper = readScalarAttribute("upper");
          bool training = readAttribute<int64_t>("training");
          run_op = [=] {
              auto self = peek(0, 2);
              auto noise = peek(1, 2);
              auto the_result = at::rrelu_with_noise(self, noise, lower, upper, training);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 917: { // rrelu_with_noise
          at::Scalar lower = readScalarAttribute("lower");
          at::Scalar upper = readScalarAttribute("upper");
          run_op = [=] {
              auto self = peek(0, 2);
              auto noise = peek(1, 2);
              auto the_result = at::rrelu_with_noise(self, noise, lower, upper);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 918: { // rrelu_with_noise
          at::Scalar lower = readScalarAttribute("lower");
          run_op = [=] {
              auto self = peek(0, 2);
              auto noise = peek(1, 2);
              auto the_result = at::rrelu_with_noise(self, noise, lower);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 919: { // rrelu_with_noise
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto noise = peek(1, 2);
              auto the_result = at::rrelu_with_noise(self, noise);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 920: { // rrelu_with_noise_backward
          at::Scalar lower = readScalarAttribute("lower");
          at::Scalar upper = readScalarAttribute("upper");
          bool training = readAttribute<int64_t>("training");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto noise = peek(2, 3);
              auto the_result = at::rrelu_with_noise_backward(grad_output, self, noise, lower, upper, training);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 921: { // softplus
          at::Scalar beta = readScalarAttribute("beta");
          at::Scalar threshold = readScalarAttribute("threshold");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::softplus(self, beta, threshold);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 922: { // softplus
          at::Scalar beta = readScalarAttribute("beta");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::softplus(self, beta);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 923: { // softplus
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::softplus(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 924: { // softplus_backward
          at::Scalar beta = readScalarAttribute("beta");
          at::Scalar threshold = readScalarAttribute("threshold");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto output = peek(2, 3);
              auto the_result = at::softplus_backward(grad_output, self, beta, threshold, output);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 925: { // softshrink
          at::Scalar lambd = readScalarAttribute("lambd");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::softshrink(self, lambd);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 926: { // softshrink
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::softshrink(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 927: { // softshrink_backward
          at::Scalar lambd = readScalarAttribute("lambd");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::softshrink_backward(grad_output, self, lambd);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 928: { // adaptive_avg_pool2d
          auto output_size = readIntArrayRef("output_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::adaptive_avg_pool2d(self, output_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 929: { // mkldnn_adaptive_avg_pool2d
          auto output_size = readIntArrayRef("output_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::mkldnn_adaptive_avg_pool2d(self, output_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 930: { // _adaptive_avg_pool2d
          auto output_size = readIntArrayRef("output_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_adaptive_avg_pool2d(self, output_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 931: { // _adaptive_avg_pool2d_backward
      
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::_adaptive_avg_pool2d_backward(grad_output, self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 932: { // adaptive_avg_pool3d
          auto output_size = readIntArrayRef("output_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::adaptive_avg_pool3d(self, output_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 933: { // adaptive_avg_pool3d_backward
      
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::adaptive_avg_pool3d_backward(grad_output, self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 934: { // adaptive_max_pool2d
          auto output_size = readIntArrayRef("output_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::adaptive_max_pool2d(self, output_size);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 935: { // adaptive_max_pool2d_backward
      
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto indices = peek(2, 3);
              auto the_result = at::adaptive_max_pool2d_backward(grad_output, self, indices);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 936: { // adaptive_max_pool3d
          auto output_size = readIntArrayRef("output_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::adaptive_max_pool3d(self, output_size);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 937: { // adaptive_max_pool3d_backward
      
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto indices = peek(2, 3);
              auto the_result = at::adaptive_max_pool3d_backward(grad_output, self, indices);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 938: { // avg_pool2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          bool ceil_mode = readAttribute<int64_t>("ceil_mode");
          bool count_include_pad = readAttribute<int64_t>("count_include_pad");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::avg_pool2d(self, kernel_size, stride, padding, ceil_mode, count_include_pad);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 939: { // avg_pool2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          bool ceil_mode = readAttribute<int64_t>("ceil_mode");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::avg_pool2d(self, kernel_size, stride, padding, ceil_mode);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 940: { // avg_pool2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::avg_pool2d(self, kernel_size, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 941: { // avg_pool2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::avg_pool2d(self, kernel_size, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 942: { // avg_pool2d
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::avg_pool2d(self, kernel_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 943: { // avg_pool3d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          bool ceil_mode = readAttribute<int64_t>("ceil_mode");
          bool count_include_pad = readAttribute<int64_t>("count_include_pad");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::avg_pool3d(self, kernel_size, stride, padding, ceil_mode, count_include_pad);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 944: { // avg_pool3d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          bool ceil_mode = readAttribute<int64_t>("ceil_mode");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::avg_pool3d(self, kernel_size, stride, padding, ceil_mode);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 945: { // avg_pool3d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::avg_pool3d(self, kernel_size, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 946: { // avg_pool3d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::avg_pool3d(self, kernel_size, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 947: { // avg_pool3d
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::avg_pool3d(self, kernel_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 948: { // fractional_max_pool2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto output_size = readIntArrayRef("output_size");
          run_op = [=] {
              auto self = peek(0, 2);
              auto random_samples = peek(1, 2);
              auto the_result = at::fractional_max_pool2d(self, kernel_size, output_size, random_samples);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 949: { // fractional_max_pool2d_backward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto output_size = readIntArrayRef("output_size");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto indices = peek(2, 3);
              auto the_result = at::fractional_max_pool2d_backward(grad_output, self, kernel_size, output_size, indices);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 950: { // fractional_max_pool3d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto output_size = readIntArrayRef("output_size");
          run_op = [=] {
              auto self = peek(0, 2);
              auto random_samples = peek(1, 2);
              auto the_result = at::fractional_max_pool3d(self, kernel_size, output_size, random_samples);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 951: { // fractional_max_pool3d_backward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto output_size = readIntArrayRef("output_size");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto indices = peek(2, 3);
              auto the_result = at::fractional_max_pool3d_backward(grad_output, self, kernel_size, output_size, indices);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 952: { // max_pool2d_with_indices
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          bool ceil_mode = readAttribute<int64_t>("ceil_mode");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool2d_with_indices(self, kernel_size, stride, padding, dilation, ceil_mode);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 953: { // max_pool2d_with_indices
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool2d_with_indices(self, kernel_size, stride, padding, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 954: { // max_pool2d_with_indices
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool2d_with_indices(self, kernel_size, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 955: { // max_pool2d_with_indices
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool2d_with_indices(self, kernel_size, stride);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 956: { // max_pool2d_with_indices
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool2d_with_indices(self, kernel_size);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 957: { // max_pool2d_with_indices_backward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          bool ceil_mode = readAttribute<int64_t>("ceil_mode");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto indices = peek(2, 3);
              auto the_result = at::max_pool2d_with_indices_backward(grad_output, self, kernel_size, stride, padding, dilation, ceil_mode, indices);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 958: { // max_pool3d_with_indices
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          bool ceil_mode = readAttribute<int64_t>("ceil_mode");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool3d_with_indices(self, kernel_size, stride, padding, dilation, ceil_mode);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 959: { // max_pool3d_with_indices
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool3d_with_indices(self, kernel_size, stride, padding, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 960: { // max_pool3d_with_indices
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool3d_with_indices(self, kernel_size, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 961: { // max_pool3d_with_indices
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool3d_with_indices(self, kernel_size, stride);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 962: { // max_pool3d_with_indices
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool3d_with_indices(self, kernel_size);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 963: { // max_pool3d_with_indices_backward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          bool ceil_mode = readAttribute<int64_t>("ceil_mode");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto indices = peek(2, 3);
              auto the_result = at::max_pool3d_with_indices_backward(grad_output, self, kernel_size, stride, padding, dilation, ceil_mode, indices);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 964: { // max_unpool2d
          auto output_size = readIntArrayRef("output_size");
          run_op = [=] {
              auto self = peek(0, 2);
              auto indices = peek(1, 2);
              auto the_result = at::max_unpool2d(self, indices, output_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 965: { // max_unpool2d_backward
          auto output_size = readIntArrayRef("output_size");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto indices = peek(2, 3);
              auto the_result = at::max_unpool2d_backward(grad_output, self, indices, output_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 966: { // max_unpool3d
          auto output_size = readIntArrayRef("output_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 2);
              auto indices = peek(1, 2);
              auto the_result = at::max_unpool3d(self, indices, output_size, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 967: { // max_unpool3d_backward
          auto output_size = readIntArrayRef("output_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto indices = peek(2, 3);
              auto the_result = at::max_unpool3d_backward(grad_output, self, indices, output_size, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 968: { // reflection_pad1d
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::reflection_pad1d(self, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 969: { // reflection_pad1d_backward
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::reflection_pad1d_backward(grad_output, self, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 970: { // reflection_pad2d
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::reflection_pad2d(self, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 971: { // reflection_pad2d_backward
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::reflection_pad2d_backward(grad_output, self, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 972: { // replication_pad1d
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::replication_pad1d(self, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 973: { // replication_pad1d_backward
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::replication_pad1d_backward(grad_output, self, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 974: { // replication_pad2d
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::replication_pad2d(self, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 975: { // replication_pad2d_backward
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::replication_pad2d_backward(grad_output, self, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 976: { // replication_pad3d
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::replication_pad3d(self, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 977: { // replication_pad3d_backward
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::replication_pad3d_backward(grad_output, self, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 978: { // upsample_linear1d
          auto output_size = readIntArrayRef("output_size");
          bool align_corners = readAttribute<int64_t>("align_corners");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::upsample_linear1d(self, output_size, align_corners);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 979: { // upsample_linear1d_backward
          auto output_size = readIntArrayRef("output_size");
          auto input_size = readIntArrayRef("input_size");
          bool align_corners = readAttribute<int64_t>("align_corners");
          run_op = [=] {
              auto grad_output = peek(0, 1);
              auto the_result = at::upsample_linear1d_backward(grad_output, output_size, input_size, align_corners);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 980: { // upsample_bilinear2d
          auto output_size = readIntArrayRef("output_size");
          bool align_corners = readAttribute<int64_t>("align_corners");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::upsample_bilinear2d(self, output_size, align_corners);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 981: { // upsample_bilinear2d_backward
          auto output_size = readIntArrayRef("output_size");
          auto input_size = readIntArrayRef("input_size");
          bool align_corners = readAttribute<int64_t>("align_corners");
          run_op = [=] {
              auto grad_output = peek(0, 1);
              auto the_result = at::upsample_bilinear2d_backward(grad_output, output_size, input_size, align_corners);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 982: { // upsample_bicubic2d
          auto output_size = readIntArrayRef("output_size");
          bool align_corners = readAttribute<int64_t>("align_corners");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::upsample_bicubic2d(self, output_size, align_corners);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 983: { // upsample_bicubic2d_backward
          auto output_size = readIntArrayRef("output_size");
          auto input_size = readIntArrayRef("input_size");
          bool align_corners = readAttribute<int64_t>("align_corners");
          run_op = [=] {
              auto grad_output = peek(0, 1);
              auto the_result = at::upsample_bicubic2d_backward(grad_output, output_size, input_size, align_corners);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 984: { // upsample_trilinear3d
          auto output_size = readIntArrayRef("output_size");
          bool align_corners = readAttribute<int64_t>("align_corners");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::upsample_trilinear3d(self, output_size, align_corners);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 985: { // upsample_trilinear3d_backward
          auto output_size = readIntArrayRef("output_size");
          auto input_size = readIntArrayRef("input_size");
          bool align_corners = readAttribute<int64_t>("align_corners");
          run_op = [=] {
              auto grad_output = peek(0, 1);
              auto the_result = at::upsample_trilinear3d_backward(grad_output, output_size, input_size, align_corners);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 986: { // upsample_nearest1d
          auto output_size = readIntArrayRef("output_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::upsample_nearest1d(self, output_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 987: { // upsample_nearest1d_backward
          auto output_size = readIntArrayRef("output_size");
          auto input_size = readIntArrayRef("input_size");
          run_op = [=] {
              auto grad_output = peek(0, 1);
              auto the_result = at::upsample_nearest1d_backward(grad_output, output_size, input_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 988: { // upsample_nearest2d
          auto output_size = readIntArrayRef("output_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::upsample_nearest2d(self, output_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 989: { // upsample_nearest2d_backward
          auto output_size = readIntArrayRef("output_size");
          auto input_size = readIntArrayRef("input_size");
          run_op = [=] {
              auto grad_output = peek(0, 1);
              auto the_result = at::upsample_nearest2d_backward(grad_output, output_size, input_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 990: { // upsample_nearest3d
          auto output_size = readIntArrayRef("output_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::upsample_nearest3d(self, output_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 991: { // upsample_nearest3d_backward
          auto output_size = readIntArrayRef("output_size");
          auto input_size = readIntArrayRef("input_size");
          run_op = [=] {
              auto grad_output = peek(0, 1);
              auto the_result = at::upsample_nearest3d_backward(grad_output, output_size, input_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 992: { // sigmoid_backward
      
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto output = peek(1, 2);
              auto the_result = at::sigmoid_backward(grad_output, output);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 993: { // tanh_backward
      
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto output = peek(1, 2);
              auto the_result = at::tanh_backward(grad_output, output);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 994: { // slow_conv_transpose2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto output_padding = readIntArrayRef("output_padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::slow_conv_transpose2d(self, weight, kernel_size, bias, stride, padding, output_padding, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 995: { // slow_conv_transpose2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto output_padding = readIntArrayRef("output_padding");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::slow_conv_transpose2d(self, weight, kernel_size, bias, stride, padding, output_padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 996: { // slow_conv_transpose2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::slow_conv_transpose2d(self, weight, kernel_size, bias, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 997: { // slow_conv_transpose2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::slow_conv_transpose2d(self, weight, kernel_size, bias, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 998: { // slow_conv_transpose2d
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::slow_conv_transpose2d(self, weight, kernel_size, bias);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 999: { // slow_conv_transpose2d
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::slow_conv_transpose2d(self, weight, kernel_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1000: { // slow_conv_transpose2d_backward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto output_padding = readIntArrayRef("output_padding");
          auto dilation = readIntArrayRef("dilation");
          auto output_mask = readBoolMask<3>("output_mask");
          run_op = [=] {
              auto grad_output = peek(0, 5);
              auto self = peek(1, 5);
              auto weight = peek(2, 5);
              auto columns = peek(3, 5);
              auto ones = peek(4, 5);
              auto the_result = at::slow_conv_transpose2d_backward(grad_output, self, weight, kernel_size, stride, padding, output_padding, dilation, columns, ones, output_mask);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 1001: { // slow_conv_transpose3d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto output_padding = readIntArrayRef("output_padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::slow_conv_transpose3d(self, weight, kernel_size, bias, stride, padding, output_padding, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1002: { // slow_conv_transpose3d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto output_padding = readIntArrayRef("output_padding");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::slow_conv_transpose3d(self, weight, kernel_size, bias, stride, padding, output_padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1003: { // slow_conv_transpose3d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::slow_conv_transpose3d(self, weight, kernel_size, bias, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1004: { // slow_conv_transpose3d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::slow_conv_transpose3d(self, weight, kernel_size, bias, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1005: { // slow_conv_transpose3d
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::slow_conv_transpose3d(self, weight, kernel_size, bias);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1006: { // slow_conv_transpose3d
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::slow_conv_transpose3d(self, weight, kernel_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1007: { // slow_conv_transpose3d_backward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto output_padding = readIntArrayRef("output_padding");
          auto dilation = readIntArrayRef("dilation");
          auto output_mask = readBoolMask<3>("output_mask");
          run_op = [=] {
              auto grad_output = peek(0, 5);
              auto self = peek(1, 5);
              auto weight = peek(2, 5);
              auto finput = peek(3, 5);
              auto fgrad_input = peek(4, 5);
              auto the_result = at::slow_conv_transpose3d_backward(grad_output, self, weight, kernel_size, stride, padding, output_padding, dilation, finput, fgrad_input, output_mask);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 1008: { // thnn_conv2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv2d(self, weight, kernel_size, bias, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1009: { // thnn_conv2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv2d(self, weight, kernel_size, bias, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1010: { // thnn_conv2d
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv2d(self, weight, kernel_size, bias);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1011: { // thnn_conv2d
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::thnn_conv2d(self, weight, kernel_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1012: { // thnn_conv2d_forward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv2d_forward(self, weight, kernel_size, bias, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 1013: { // thnn_conv2d_backward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto output_mask = readBoolMask<3>("output_mask");
          run_op = [=] {
              auto grad_output = peek(0, 5);
              auto self = peek(1, 5);
              auto weight = peek(2, 5);
              auto finput = peek(3, 5);
              auto fgrad_input = peek(4, 5);
              auto the_result = at::thnn_conv2d_backward(grad_output, self, weight, kernel_size, stride, padding, finput, fgrad_input, output_mask);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 1014: { // thnn_conv_depthwise2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv_depthwise2d(self, weight, kernel_size, bias, stride, padding, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1015: { // thnn_conv_depthwise2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv_depthwise2d(self, weight, kernel_size, bias, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1016: { // thnn_conv_depthwise2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv_depthwise2d(self, weight, kernel_size, bias, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1017: { // thnn_conv_depthwise2d
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv_depthwise2d(self, weight, kernel_size, bias);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1018: { // thnn_conv_depthwise2d
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::thnn_conv_depthwise2d(self, weight, kernel_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1019: { // thnn_conv_depthwise2d_forward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv_depthwise2d_forward(self, weight, kernel_size, bias, stride, padding, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1020: { // thnn_conv_depthwise2d_backward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          auto output_mask = readBoolMask<2>("output_mask");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::thnn_conv_depthwise2d_backward(grad_output, self, weight, kernel_size, stride, padding, dilation, output_mask);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 1021: { // thnn_conv3d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv3d(self, weight, kernel_size, bias, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1022: { // thnn_conv3d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv3d(self, weight, kernel_size, bias, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1023: { // thnn_conv3d
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv3d(self, weight, kernel_size, bias);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1024: { // thnn_conv3d
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::thnn_conv3d(self, weight, kernel_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1025: { // thnn_conv3d_forward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv3d_forward(self, weight, kernel_size, bias, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 1026: { // thnn_conv3d_backward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto output_mask = readBoolMask<3>("output_mask");
          run_op = [=] {
              auto grad_output = peek(0, 5);
              auto self = peek(1, 5);
              auto weight = peek(2, 5);
              auto finput = peek(3, 5);
              auto fgrad_input = peek(4, 5);
              auto the_result = at::thnn_conv3d_backward(grad_output, self, weight, kernel_size, stride, padding, finput, fgrad_input, output_mask);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 1027: { // slow_conv_dilated2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::slow_conv_dilated2d(self, weight, kernel_size, bias, stride, padding, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1028: { // slow_conv_dilated2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::slow_conv_dilated2d(self, weight, kernel_size, bias, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1029: { // slow_conv_dilated2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::slow_conv_dilated2d(self, weight, kernel_size, bias, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1030: { // slow_conv_dilated2d
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::slow_conv_dilated2d(self, weight, kernel_size, bias);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1031: { // slow_conv_dilated2d
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::slow_conv_dilated2d(self, weight, kernel_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1032: { // slow_conv_dilated2d_backward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          auto output_mask = readBoolMask<3>("output_mask");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::slow_conv_dilated2d_backward(grad_output, self, weight, kernel_size, stride, padding, dilation, output_mask);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 1033: { // slow_conv_dilated3d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::slow_conv_dilated3d(self, weight, kernel_size, bias, stride, padding, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1034: { // slow_conv_dilated3d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::slow_conv_dilated3d(self, weight, kernel_size, bias, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1035: { // slow_conv_dilated3d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::slow_conv_dilated3d(self, weight, kernel_size, bias, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1036: { // slow_conv_dilated3d
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::slow_conv_dilated3d(self, weight, kernel_size, bias);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1037: { // slow_conv_dilated3d
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::slow_conv_dilated3d(self, weight, kernel_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1038: { // slow_conv_dilated3d_backward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          auto output_mask = readBoolMask<3>("output_mask");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::slow_conv_dilated3d_backward(grad_output, self, weight, kernel_size, stride, padding, dilation, output_mask);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 1039: { // col2im
          auto output_size = readIntArrayRef("output_size");
          auto kernel_size = readIntArrayRef("kernel_size");
          auto dilation = readIntArrayRef("dilation");
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::col2im(self, output_size, kernel_size, dilation, padding, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1040: { // col2im_backward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto dilation = readIntArrayRef("dilation");
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto grad_output = peek(0, 1);
              auto the_result = at::col2im_backward(grad_output, kernel_size, dilation, padding, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1041: { // im2col
          auto kernel_size = readIntArrayRef("kernel_size");
          auto dilation = readIntArrayRef("dilation");
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::im2col(self, kernel_size, dilation, padding, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1042: { // im2col_backward
          auto input_size = readIntArrayRef("input_size");
          auto kernel_size = readIntArrayRef("kernel_size");
          auto dilation = readIntArrayRef("dilation");
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto grad_output = peek(0, 1);
              auto the_result = at::im2col_backward(grad_output, input_size, kernel_size, dilation, padding, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      default:
        CAFFE_THROW("Unexpected key value for aten operator");
    }
  }
  USE_OPERATOR_CONTEXT_FUNCTIONS;

  bool RunOnDevice() override {
    return run_op();
  }
private:
  // actual operator implementation is initialized in ctor.
  std::function<bool()> run_op;
  at::Backend backend() const;

  TypeMeta typeMetaFor(const at::Tensor & t) {
    return typeMetaFor(t.scalar_type());
  }
  TypeMeta typeMetaFor(at::ScalarType st) {
    #define DEFINE_CASE(ctype,aten_name) \
      case at::k##aten_name: \
        return TypeMeta::Make<ctype>();
    switch(st) {
      AT_FORALL_SCALAR_TYPES_AND2(Bool, BFloat16, DEFINE_CASE)
    default:
      CAFFE_THROW("Unknown ATen Type");
    }
    #undef DEFINE_CASE
  }

  at::TensorOptions optionsFor(const Tensor& ten) {
    at::Device device = ten.GetDevice();
#ifdef __HIP_PLATFORM_HCC__
    if (backend() == at::Backend::HIP) {
      device = at::Device(kCUDA, device.index());
    }
#endif
    return at::TensorOptions(device).dtype(ten.dtype());
  }

  at::Tensor tensorWrapping(const Tensor& ten_) {
    auto& ten = const_cast<Tensor&>(ten_);
    return at::from_blob(
        ten.raw_mutable_data(),
        ten.sizes(),
        optionsFor(ten));
  }

  at::Tensor peek(size_t i, size_t N) {
    auto real_idx = InputSize() - N + i;
    return tensorWrapping(Input(real_idx));
  }

  std::vector<at::Tensor> peekSlice(size_t i, size_t len, size_t N) {
    std::vector<at::Tensor> results;
    for (size_t ii = i; ii < i + len; ++ii) {
      results.push_back(peek(ii, N));
    }
    return results;
  }

  void assignTo(Tensor* dst, const at::Tensor& src_) {
    at::Tensor src = src_.contiguous();
    auto at_sizes = src.sizes();
    caffe2::TypeMeta type_meta = typeMetaFor(src);
    at::Device device = src.device();
#ifdef __HIP_PLATFORM_HCC__
    if (device.type() == at::DeviceType::CUDA) {
      device = at::Device(at::DeviceType::HIP, device.index());
    }
#endif
    at::TensorImpl* src_impl = src.unsafeReleaseTensorImpl();
    std::vector<int64_t> dims(at_sizes.begin(), at_sizes.end());
    dst->Resize(dims);
    dst->ShareExternalPointer(
        at::DataPtr(
            src_impl->data(),
            static_cast<void*>(src_impl),
            [](void* t_ptr) -> void {
              at::TensorImpl* local_impl = static_cast<at::TensorImpl*>(t_ptr);
              c10::raw::intrusive_ptr::decref(local_impl);
            },
            device),
        type_meta,
        0);
  }
  void assignListStartingAt(
      size_t offset,
      const std::vector<at::Tensor>& tensors) {
    for (size_t i = 0; i < tensors.size(); i++) {
      assignTo(Output(offset + i), tensors[i]);
    }
  }

  template<typename T,
          typename std::enable_if<std::numeric_limits<T>::is_integer, bool>::type* =
              nullptr>
  int64_t extract(const at::Scalar &s) {
    return s.toLong();
  }

  template<typename T,
          typename std::enable_if<!std::numeric_limits<T>::is_integer, bool>::type* =
              nullptr>
  int64_t extract(const at::Scalar &s) {
    return s.toDouble();
  }

  void assignTo(Tensor* dst, at::ScalarType scalar_type, at::Scalar scalar) {
    switch(scalar_type) {
      #define DEFINE_CASE(ctype,aten_name) \
        case at::k##aten_name: { \
          auto value = extract<ctype>(scalar); \
          assignToValue<ctype>(dst, at::convert<ctype,decltype(value)>(value)); \
        } break;
      AT_FORALL_SCALAR_TYPES_AND2(Bool, BFloat16, DEFINE_CASE)
#undef DEFINE_CASE
      default:
        CAFFE_THROW("Unknown ATen Type");
    }
  }
  template <typename T>
  void assignToValue(Tensor* dst, T v) {
    dst->Resize(std::vector<int64_t>());
    math::Set(1, v, dst->template mutable_data<T>(), &context_);
  }
  int findImplementation(const OperatorDef& operator_def) {
    CAFFE_ENFORCE(HasArgument("operator"));
    std::string op = OperatorBase::GetSingleArgument<std::string>("operator", "");
    // construct descriptor string ([DESCRIPTORS]) given the attributes
    // and inputs of this operator_def, and look up the implementation key
    // for this variant
    std::stringstream descriptor;
    descriptor << op;
    std::vector<std::string> attrs;
    for(size_t i = 0; i < operator_def.arg_size(); i++) {
      auto & attr = operator_def.arg(i);
      if(attr.name() == "operator" || attr.name() == "type" )
        continue;
      attrs.push_back(attr.name());
    }
    std::sort(attrs.begin(), attrs.end());
    for(auto & a : attrs)
      descriptor << "-" << a;

    std::string descriptor_sized =
        descriptor.str() + "-" + c10::to_string(InputSize());
    std::string descriptor_var_args = descriptor.str() + "-*";
    if (op_to_key.count(descriptor_sized) > 0) {
      return op_to_key[descriptor_sized];
    }
    if (op_to_key.count(descriptor_var_args) > 0) {
      return op_to_key[descriptor_var_args];
    }
    std::stringstream ss;
    ss << "Attempting to run unknown ATen operator configuration: "
       << descriptor_sized;
    CAFFE_THROW(ss.str());
  }
  at::Scalar readScalarAttribute(const std::string & name) {
    if(OperatorBase::HasSingleArgumentOfType<int64_t>(name)) {
      return OperatorBase::GetSingleArgument<int64_t>(name, 0);
    } else {
      CAFFE_ENFORCE(OperatorBase::HasSingleArgumentOfType<float>(name));
      return OperatorBase::GetSingleArgument<float>(name, 0);
    }
  }
  template<typename T>
  T readAttribute(const std::string & name) {
    CAFFE_ENFORCE(OperatorBase::HasSingleArgumentOfType<T>(name));
    return OperatorBase::GetSingleArgument<T>(name, 0);
  }
  std::vector<int64_t> readIntArrayRef(const std::string & name) {
    CAFFE_ENFORCE(OperatorBase::HasArgument(name));
    return OperatorBase::GetRepeatedArgument<int64_t>(name, {});
  }
  template <int N>
  std::array<bool, N> readBoolMask(const std::string& name) {
    CAFFE_ENFORCE(OperatorBase::HasArgument(name));
    std::vector<int64_t> ints =
        OperatorBase::GetRepeatedArgument<int64_t>(name, {});
    std::array<bool, N> result;
    for (size_t i = 0; i < N; ++i) {
      result[i] = ints.at(i);
    }
    return result;
  }
};

}
