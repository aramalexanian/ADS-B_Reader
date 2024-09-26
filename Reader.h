#pragma once
#include <cstdint>
#include <string>
#include <iostream>

namespace read {
	class Reader {
	private:
		uint64_t code_1;
		uint64_t code_2;

	public:
		Reader(uint64_t code_1, uint64_t code_2);

		uint8_t DownlinkFormat();
		uint8_t TrasnponderCapability();
		uint32_t IcaoAircraftAddress();
		uint64_t MessageExtendedSquitter();
		uint8_t TypeCode();
		uint32_t ParityInteerrogatorId();

		std::string Mode();
		std::string CapabilityMessage();
		std::string TypeCodeMessage();
		std::string decode();
		std::string decodeModeS(int format);
		char addChar(int num);
	};
}