import 'package:grpc/grpc.dart';
import 'package:client/service.pbgrpc.dart';

class Receiver {
  static final Receiver _instance = Receiver._internal();

  factory Receiver() {
    return _instance;
  }

  Receiver._internal();

  void receiveStream() {
    ClientChannel channel = ClientChannel(
      "172.30.234.77",
      port: 50051,
      options: const ChannelOptions(
        credentials: ChannelCredentials.insecure(),
        connectTimeout: Duration(seconds: 2),
        connectionTimeout: Duration(seconds: 2),
      ),
    );

    GrpcServiceClient client = GrpcServiceClient(channel);
    ResponseStream<Reply> call = client.getStream(Empty());

    call.listen(
      (data) {
        // print("received data from sever");
      },
      onError: (error) {
        print("error $error");
      },
      onDone: () {
        print("done");
      },
      cancelOnError: true,
    );
  }
}
