//
//  Generated code. Do not modify.
//  source: service.proto
//
// @dart = 2.12

// ignore_for_file: annotate_overrides, camel_case_types, comment_references
// ignore_for_file: constant_identifier_names, library_prefixes
// ignore_for_file: non_constant_identifier_names, prefer_final_fields
// ignore_for_file: unnecessary_import, unnecessary_this, unused_import

import 'dart:async' as $async;
import 'dart:core' as $core;

import 'package:grpc/service_api.dart' as $grpc;
import 'package:protobuf/protobuf.dart' as $pb;

import 'service.pb.dart' as $0;

export 'service.pb.dart';

@$pb.GrpcServiceName('GrpcService')
class GrpcServiceClient extends $grpc.Client {
  static final _$getStream = $grpc.ClientMethod<$0.Empty, $0.Reply>(
      '/GrpcService/GetStream',
      ($0.Empty value) => value.writeToBuffer(),
      ($core.List<$core.int> value) => $0.Reply.fromBuffer(value));

  GrpcServiceClient($grpc.ClientChannel channel,
      {$grpc.CallOptions? options,
      $core.Iterable<$grpc.ClientInterceptor>? interceptors})
      : super(channel, options: options,
        interceptors: interceptors);

  $grpc.ResponseStream<$0.Reply> getStream($0.Empty request, {$grpc.CallOptions? options}) {
    return $createStreamingCall(_$getStream, $async.Stream.fromIterable([request]), options: options);
  }
}

@$pb.GrpcServiceName('GrpcService')
abstract class GrpcServiceBase extends $grpc.Service {
  $core.String get $name => 'GrpcService';

  GrpcServiceBase() {
    $addMethod($grpc.ServiceMethod<$0.Empty, $0.Reply>(
        'GetStream',
        getStream_Pre,
        false,
        true,
        ($core.List<$core.int> value) => $0.Empty.fromBuffer(value),
        ($0.Reply value) => value.writeToBuffer()));
  }

  $async.Stream<$0.Reply> getStream_Pre($grpc.ServiceCall call, $async.Future<$0.Empty> request) async* {
    yield* getStream(call, await request);
  }

  $async.Stream<$0.Reply> getStream($grpc.ServiceCall call, $0.Empty request);
}
