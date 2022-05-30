import tensorflow as tf

class ImageClassifier:
    def __init__(self, img_shape_x, img_shape_y, num_labels):
        super(ImageClassifier, self).__init__()
        self.img_shape_x = img_shape_x
        self.img_shape_y = img_shape_y
        self.num_labels = num_labels
        self.classifier = None

    def configure_model(self):
        input_layer = tf.keras.Input(shape=[self.img_shape_x, self.img_shape_y,])
        flatten_layer = tf.keras.layers.Flatten()(input_layer)

        ac_func_relu = tf.keras.activations.relu
        hidden_layer_1 = tf.keras.layers.Dense(units=128, activations=ac_func_relu)(flatten_layer)
        hidden_layer_2 = tf.keras.layers.Dense(units=128, activations=ac_func_relu)(hidden_layer_1)

        ac_func_softmax = tf.keras.activations.softmax
        output_layer = tf.keras.layers.Dense(units=self.num_labels, activations=ac_func_softmax)(hidden_layer_2)
        self.classifier = tf.keras.Model(inputs=input_layer, outputs=output_layer)

        opt_alg = tf.keras.optimizers.Adam(learning_rate=0.001)
        loss_cross_e = tf.keras.losses.SparseCategoricalCrossentropy(from_logits=False)
        self.classifier.compile(optimizer=opt_alg, loss=loss_cross_e, metrics=['accuracy'])

    def fit(self, train_imgs, train_labels, num_epochs):
        self.classifier.fit(x=train_imgs, y=train_labels, epochs=num_epochs)

    def predict(self, test_imgs):
        predictions = self.classifier.predict(test_imgs)
        return predictions
