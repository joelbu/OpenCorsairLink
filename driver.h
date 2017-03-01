/*
 * This file is part of OpenCorsairLink.
 * Copyright (C) 2017  Sean Nelson <audiohacked@gmail.com>

 * OpenCorsairLink is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * any later version.

 * OpenCorsairLink is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with OpenCorsairLink.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _DRIVER_H
#define _DRIVER_H

struct corsair_device_driver {
	/** device communication helper functions */
	int (*init)(struct libusb_device_handle*, uint8_t);
	int (*deinit)(struct libusb_device_handle*, uint8_t);
	int (*read)(struct libusb_device_handle*, uint8_t, uint8_t*, int);
	int (*write)(struct libusb_device_handle*, uint8_t, uint8_t*, int);
	
	/** protocol functions */
	int (*name)(struct corsair_device_info *dev, char *name);
	int (*vendor)(struct corsair_device_info *dev, char *name);
	int (*product)(struct corsair_device_info *dev, char *name);
	int (*device_id)(struct corsair_device_info *dev);
	int (*fw_version)(struct corsair_device_info *dev);
	
	int (*led)(struct corsair_device_info *dev, struct color *l, struct color *w, uint8_t t, uint8_t e);
	int (*temperature)(struct corsair_device_info *dev, uint8_t select, uint16_t *temp);

	struct fan_functions {
		int (*profile)(struct corsair_device_info *dev, uint8_t profile);
		int (*custom)(struct corsair_device_info *dev, struct fan_table *custom_profile);
	} fan;

	struct pump_functions {
		int (*profile)(struct corsair_device_info *dev, uint8_t profile);
		int (*custom)(struct corsair_device_info *dev, struct fan_table *custom_profile);
	} pump;

	struct power_functions {
		int (*supply_voltage)(struct corsair_device_info *dev, uint16_t *volts);
		int (*total_wattage)(struct corsair_device_info *dev, uint16_t *watts);
		int (*select)(struct corsair_device_info *dev, uint8_t output_select);
		int (*voltage)(struct corsair_device_info *dev, uint16_t *volts);
		int (*amperage)(struct corsair_device_info *dev, uint16_t *amps);
		int (*wattage)(struct corsair_device_info *dev, uint16_t *watts);
	} power;

	struct time_functions {
		int (*powered)(struct corsair_device_info *dev, uint32_t *v32);
		int (*uptime)(struct corsair_device_info *dev, uint32_t *v32);
	} psu_time;

	int (*fan_speed_read)();
};

#endif