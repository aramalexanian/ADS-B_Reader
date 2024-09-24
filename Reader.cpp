#include "Reader.h"

extract::Extractor::Extractor(uint64_t code_1, uint64_t code_2) {
	this->code_1 = code_1;
	this->code_2 = code_2;
}

uint8_t extract::Extractor::DownlinkFormat() {
	return code_1 >> 51;
}

uint8_t extract::Extractor::TrasnponderCapability() {
	return (code_1 & 0x07FFFFFFFFFFFF) >> 48;
}

uint32_t extract::Extractor::IcaoAircraftAddress() {
	return (code_1 & 0x00FFFFFFFFFFFF) >> 24;
}

uint64_t extract::Extractor::MessageExtendedSquitter() {
	return ((code_1 & 0x00000000FFFFFF) << 32) | (code_2 >> 24);
}

uint8_t extract::Extractor::TypeCode() {
	return (code_1 & 0x00000000FDFFFF) >> 19;
}

uint32_t extract::Extractor::ParityInteerrogatorId() {
	return code_2 & 0x00000000FFFFFF;
}