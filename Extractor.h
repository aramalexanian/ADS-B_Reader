#pragma once
#include <cstdint>

namespace extract {
	class Extractor {
	private:
		uint64_t code_1;
		uint64_t code_2;

	public:
		Extractor(uint64_t code_1, uint64_t code_2);

		uint8_t DownlinkFormat();
		uint8_t TrasnponderCapability();
		uint32_t IcaoAircraftAddress();
		uint64_t MessageExtendedSquitter();
		uint8_t TypeCode();
		uint32_t ParityInteerrogatorId();
	};
}