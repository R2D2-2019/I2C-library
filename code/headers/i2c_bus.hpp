#pragma once

#include <hwlib.hpp>

namespace r2d2::i2c {
    /**
     * class i2c_bus_c
     * Provides hardware I2C functionality to the arduino due.
     */
    class i2c_bus_c {
    private:
        /**
         * Selected interface
         *
         * @internal
         */
        Twi *_selected;
        /**
         * Clock speed of the instance
         * @internal
         */
        uint32_t SPEED = 0; ///< Clock>
        /**
         * Initializes the pins (scl1 & sda1 for TWI1 and scl & sda for TWI0)
         * @internal
         */
        void pin_init();
        /**
         * Initializes the clock for the hardware i2c instance
         * @internal
         */
        void clock_init();
        /**
         * initializes the hardware i2c bus on the selected_interface
         * @internal
         */
        void init();
        /**
         * Writes the given byte on the selected I2C interface
         * @internal
         */
        void write_byte(const uint8_t data);
        /**
         * Reads and returns 1 byte from the selected i2c interface
         * @internal
         */
        uint8_t read_byte();

    public:
        /**
         * Enum of the possible interface you can select when instantiating this
         * class.
         */
        enum class interface { interface_0, interface_1 };
        /**
         * Constructor for the i2c instance, takes the selected interface and
         * the bus speed as parameters.
         *
         * @param interface - the selected interface
         * @param speed - the clock speed
         */
        i2c_bus_c(const interface &selected_interface, const uint32_t SPEED);

        /**
         * Writes n bytes on the i2c bus to the given address
         *
         * @param address - the device address
         * @param data - the data to send
         * @param n - amount of bytes to write
         */
        void write(const uint_fast8_t address, const uint8_t data[],
                   const size_t n, const uint8_t *internal_address = nullptr,
                   const uint8_t internal_address_size = 0);

        /**
         * Reads n bytes from the i2c bus from the given address
         *
         * @param address - the device address
         * @param data - the data to read
         * @param n - the amount of b to read
         */
        void read(const uint8_t address, uint8_t *data, const uint32_t n,
                  const uint8_t *internal_address = nullptr,
                  const uint8_t internal_address_size = 0);
    };
}; // namespace r2d2::i2c