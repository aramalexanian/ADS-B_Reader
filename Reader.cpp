#include "Reader.h"

read::Reader::Reader(uint64_t code_1, uint64_t code_2) {
	this->code_1 = code_1;
	this->code_2 = code_2;
}

uint8_t read::Reader::DownlinkFormat() {
	return code_1 >> 51;
}

uint8_t read::Reader::TrasnponderCapability() {
	return (code_1 & 0x07FFFFFFFFFFFF) >> 48;
}

uint32_t read::Reader::IcaoAircraftAddress() {
	return (code_1 & 0x00FFFFFFFFFFFF) >> 24;
}

uint64_t read::Reader::MessageExtendedSquitter() {
	return ((code_1 & 0x00000000FFFFFF) << 32) | (code_2 >> 24);
}

uint8_t read::Reader::TypeCode() {
	return (code_1 & 0x00000000FDFFFF) >> 19;
}

uint32_t read::Reader::ParityInteerrogatorId() {
	return code_2 & 0x00000000FFFFFF;
}

std::string read::Reader::Mode() {
	std::string str = "";
	switch (DownlinkFormat()) {
	case 17:
		str = "Mode~S Extended Sqitter (ADS)";
		break;
	case 18:
		str = "None-Transponder-Based (ADS-B) or TIS-B";
		break;
	}
	return str;
}

std::string read::Reader::TypeCodeMessage() {
	std::string str = "";
	switch (TypeCode()) {
	case 1: case 2: case 3: case 4:
		str = "Aircraft Identification";
		break;
	case 5: case 6: case 7: case 8:
		str = "Surface Position";
		break;
	case 9: case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18:
		str = "Airborne position(w/Baro Altitude)";
		break;
	case 19:
		str = "Airborne Velocities";
		break;
	case 20: case 21: case 22:
		str = "Airborne position(w/GNSS Height)";
		break;
	case 23: case 24: case 25: case 26: case 27:
		str = "Reversed";
		break;
	case 28:
		str = "Aircraft Status";
		break;
	case 29:
		str = "Target state and status information";
		break;
	case 31:
		str = "Aircraft Operation status";
		break;
	}
	return str;
}

std::string read::Reader::CapabilityMessage() {
	std::string str = "";
	switch (TrasnponderCapability()) {
	case 0:
		str = "Level 1 Transponder";
		break;
	case 1: case 2:	case 3:
		str = "Reserved";
		break;
	case 4:
		str = "Level 2+ transponder,\nwith ability to set CA to 7,\non ground";
		break;
	case 5:
		str = "Level 2+ transponder,\nwith ability to set CA to 7,\nairborne";
		break;
	case 6:
		str = "Level 2+ transponder,\nwith ability to set CA to 7,\neither on-ground or airborne";
		break;
	case 7:
		str = "Signifies the Downlink Request value is 0,\nor the Flight Status is 2, 3, 4, or 5,\neither on-ground or airborne";
		break;
	}
	return str;
}