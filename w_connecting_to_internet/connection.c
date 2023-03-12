#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "secrets.h"

int main() {
    stdio_init_all();
    sleep_ms(4000);
    if (cyw43_arch_init_with_country(CYW43_COUNTRY_SWEDEN)) {
        printf("failed to initalise\n");
    }
    printf("initialised\n");

    cyw43_arch_enable_sta_mode();

    if (cyw43_arch_wifi_connect_timeout_ms(WIFI_SSID, WIFI_PASS, CYW43_AUTH_WPA2_AES_PSK, 10000)) {
        printf("failed to connect\n");
        return 1;
    }
   
    printf("Connected to wifi with IP: %s\n", ip4addr_ntoa(netif_ip4_addr(netif_list)), 0);    
}