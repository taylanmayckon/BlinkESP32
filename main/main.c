// C includes
#include <stdio.h>

//FreeRTOS includes
#include <freertos/FreeRTOS.h>

//esp-idf includes
#include <esp_log.h>
#include <esp_err.h>
#include <driver/gpio.h>

//defines
#define LED GPIO_NUM_5


//função que configura os GPIOs
void GPIO_init(){
    const static char TAG[] = "GPIO_init";

    //configura GPIOS com a struct gpio_config
    gpio_config_t leds = {
        .pin_bit_mask = (1<<LED), //BITMASK para a porta 5
        .mode = GPIO_MODE_DEF_OUTPUT, //modo output only
        .pull_up_en = GPIO_PULLUP_DISABLE, //sem pullup
        .pull_down_en = GPIO_PULLDOWN_DISABLE,// sem pulldown
        .intr_type = GPIO_INTR_DISABLE, //interrupções desligadas 
    };

    ESP_ERROR_CHECK(gpio_config(&leds)); //inicia a configuração e verifica erros

    //configura GPIO com funções 
    gpio_set_direction(LED, GPIO_MODE_DEF_OUTPUT); // configura a porta 21 como input

    ESP_LOGI(TAG, "GPIOs configuradas!!!");
}




void app_main(void){
    const static char TAG[] = "main task"; //tag main
    GPIO_init(); //inicia as GPIOS


    while(true){
        gpio_set_level(LED, 1);
        vTaskDelay(pdMS_TO_TICKS(1000));
        gpio_set_level(LED, 0);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

