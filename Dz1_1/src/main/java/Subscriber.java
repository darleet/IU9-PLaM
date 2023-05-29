import org.eclipse.paho.client.mqttv3.*;
import org.eclipse.paho.client.mqttv3.persist.MemoryPersistence;

import static java.lang.Math.sqrt;

public class Subscriber {
    public static void main(String[] args) {
        String broker = "tcp://broker.emqx.io:1883";
        String topic = "mqtt/solution";
        String username = "emqx";
        String password = "public";
        String clientid = "subscribe_client";
        int qos = 0;

        try {
            MqttClient client = new MqttClient(broker, clientid, new MemoryPersistence());
            // connect options
            MqttConnectOptions options = new MqttConnectOptions();
            options.setUserName(username);
            options.setPassword(password.toCharArray());
            options.setConnectionTimeout(60);
            options.setKeepAliveInterval(60);
            // setup callback
            client.setCallback(new MqttCallback() {

                public void connectionLost(Throwable cause) {
                    System.out.println("connectionLost: " + cause.getMessage());
                }

                public void messageArrived(String topic, MqttMessage message) {
                    String content = new String(message.getPayload());
                    String[] coordinates = calculate(content);

                    System.out.println("topic: " + topic);
                    System.out.println("Qos: " + message.getQos());
                    System.out.println("message content: " + content);
                    System.out.println("result: " + "("
                            + coordinates[0] + ";"
                            + coordinates[1] + ";"
                            + coordinates[2] + ")\n");
                }

                public void deliveryComplete(IMqttDeliveryToken token) {
                    System.out.println("deliveryComplete---------" + token.isComplete());
                }

            });
            client.connect(options);
            client.subscribe(topic, qos);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static String[] calculate(String content) {
        String[] coordinates = content.replaceAll("\\(", "")
                .replaceAll("\\)", "")
                .split(";");
        double length = 0;

        for (String x : coordinates) {
            double doubleX = Float.parseFloat(x);
            length += doubleX * doubleX;
        }

        length = sqrt(length);

        for (int i = 0; i < coordinates.length; i++) {
            double doubleX = Float.parseFloat(coordinates[i]);
            doubleX /= length;
            coordinates[i] = String.valueOf(doubleX);
        }

        return coordinates;
    }
}