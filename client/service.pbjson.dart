//
//  Generated code. Do not modify.
//  source: service.proto
//
// @dart = 2.12

// ignore_for_file: annotate_overrides, camel_case_types, comment_references
// ignore_for_file: constant_identifier_names, library_prefixes
// ignore_for_file: non_constant_identifier_names, prefer_final_fields
// ignore_for_file: unnecessary_import, unnecessary_this, unused_import

import 'dart:convert' as $convert;
import 'dart:core' as $core;
import 'dart:typed_data' as $typed_data;

@$core.Deprecated('Use emptyDescriptor instead')
const Empty$json = {
  '1': 'Empty',
};

/// Descriptor for `Empty`. Decode as a `google.protobuf.DescriptorProto`.
final $typed_data.Uint8List emptyDescriptor = $convert.base64Decode(
    'CgVFbXB0eQ==');

@$core.Deprecated('Use replyDescriptor instead')
const Reply$json = {
  '1': 'Reply',
};

/// Descriptor for `Reply`. Decode as a `google.protobuf.DescriptorProto`.
final $typed_data.Uint8List replyDescriptor = $convert.base64Decode(
    'CgVSZXBseQ==');

const $core.Map<$core.String, $core.dynamic> GrpcServiceBase$json = {
  '1': 'GrpcService',
  '2': [
    {'1': 'GetStream', '2': '.Empty', '3': '.Reply', '6': true},
  ],
};

@$core.Deprecated('Use grpcServiceDescriptor instead')
const $core.Map<$core.String, $core.Map<$core.String, $core.dynamic>> GrpcServiceBase$messageJson = {
  '.Empty': Empty$json,
  '.Reply': Reply$json,
};

/// Descriptor for `GrpcService`. Decode as a `google.protobuf.ServiceDescriptorProto`.
final $typed_data.Uint8List grpcServiceDescriptor = $convert.base64Decode(
    'CgtHcnBjU2VydmljZRIdCglHZXRTdHJlYW0SBi5FbXB0eRoGLlJlcGx5MAE=');

