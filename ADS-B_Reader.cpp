// ADS-B_Extractor.cpp : Defines the entry point for the application.
//

#include "ADS-B_Reader.h"
#include "Reader.h"

int main()
{//		    		 0x00000000FFFFFF
	//char code[] = "8D4840D6202CC371C32CE0576098";
	int64_t code_1 = 0x8D4840D6202CC3;
	int64_t code_2 = 0x71C32CE0576098;
	read::Reader E(code_1, code_2);
	std::cout << "DF: " << (int)E.DownlinkFormat() << std::endl;
	std::cout << E.Mode() << std::endl;
	std::cout << "SP: " << (int)E.TrasnponderCapability() << std::endl;
	std::cout << E.CapabilityMessage() << std::endl;
	std::cout << "ICAO: " << std::hex << std::uppercase << E.IcaoAircraftAddress() << std::endl;
	std::cout << "ME: " << std::hex << std::uppercase << E.MessageExtendedSquitter() << std::endl;
	std::cout << E.decode() << std::endl;
	std::cout << "Type: " << (int)E.TypeCode() << std::endl;
	std::cout << E.TypeCodeMessage() << std::endl;
	std::cout << "PI: " << E.ParityInteerrogatorId() << std::endl;

	//8D40621D58C382D690C8AC2863A7 8D40621D58C386435CC412692AD6

	return 0;
}

class ADS_B{
	uint8_t DownlinkFormat;
	uint8_t TransponderCapability;
	uint32_t IcaoAircraftAddress;
	uint64_t Message;
	uint8_t TypeCode;
	uint32_t ParityInterrogatorId;
};