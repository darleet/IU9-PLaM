import org.eclipse.paho.client.mqttv3.MqttClient;
import org.eclipse.paho.client.mqttv3.MqttConnectOptions;
import org.eclipse.paho.client.mqttv3.MqttException;
import org.eclipse.paho.client.mqttv3.MqttMessage;
import org.eclipse.paho.client.mqttv3.persist.MemoryPersistence;

public class Publisher {
    public static void main(String[] args) {
        String content1 = "(" + 5 + ";" + 1 + ";" + 9 + ")";
        String content2 = "(" + 8.3 + ";" + -2.3 + ";" + 8.2 + ")";
        String content3 = "(" + -3.7 + ";" + 6.2 + ";" + 1. + ")";

        Publish(content1);
        Publish(content2);
        Publish(content3);
    }

    public static void Publish(String content) {
        String broker = "tcp://broker.emqx.io:1883";
        String topic = "mqtt/solution";
        String username = "emqx";
        String password = "public";
        String clientid = "publish_client";
        int qos = 0;

        try {
            MqttClient client = new MqttClient(broker, clientid, new MemoryPersistence());
            MqttConnectOptions options = new MqttConnectOptions();
            options.setUserName(username);
            options.setPassword(password.toCharArray());
            options.setConnectionTimeout(60);
            options.setKeepAliveInterval(60);
            // connect
            client.connect(options);
            // create message and setup QoS
            MqttMessage message = new MqttMessage(content.getBytes());
            message.setQos(qos);
            // publish message
            client.publish(topic, message);
            System.out.println("Message published");
            System.out.println("topic: " + topic);
            System.out.println("message content: " + content);
            // disconnect
            client.disconnect();
            // close client
            client.close();
            System.out.println();
        } catch (MqttException e) {
            throw new RuntimeException(e);
        }
    }

}
