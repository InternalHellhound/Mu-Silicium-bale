#include <Library/DeviceMemoryMapLib.h>

STATIC
ARM_MEMORY_REGION_DESCRIPTOR_EX
gDeviceMemoryDescriptorEx[] = {
  // Name, Address, Length, HobOption, ResourceType, ResourceAttribute, MemoryType, ArmAttribute

  // DDR Regions
  {"Hyperisor",         0x80000000, 0x00600000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, WRITE_BACK_XN},
  {"RAM Partition",     0x80600000, 0x00260000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN},
  {"AOP CMD DB",        0x80860000, 0x00020000, AddMem, MEM_RES, UNCACHEABLE, Reserv, UNCACHED_UNBUFFERED_XN},
  {"RAM Partition",     0x80880000, 0x00004000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN},
  {"XBL Log Buffer",    0x80884000, 0x00010000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, WRITE_BACK_XN},
  {"RAM Partition",     0x80894000, 0x0006C000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN},
  {"SMEM",              0x80900000, 0x00200000, AddMem, MEM_RES, UNCACHEABLE, Reserv, UNCACHED_UNBUFFERED_XN},
  {"CPUCP FW",          0x80B00000, 0x00100000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, UNCACHED_UNBUFFERED_XN},
  {"RAM Partition",     0x80C00000, 0x04600000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN},
  {"PIL Reserved",      0x85200000, 0x16600000, AddMem, MEM_RES, UNCACHEABLE, Reserv, UNCACHED_UNBUFFERED_XN},
  {"RAM Partition",     0x9B800000, 0x03C00000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN},
  {"Sched Heap",        0x9F400000, 0x00400000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK_XN},
  {"FV Region",         0x9F800000, 0x00200000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK_XN},
  {"ABOOT FV",          0x9FA00000, 0x00200000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, WRITE_BACK_XN},
  {"FD Reserved",       0x9FC00000, 0x00100000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK},
  {"UEFI FD",           0x9FD00000, 0x00200000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK},
  {"SEC Heap",          0x9FF00000, 0x0008C000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK_XN},
  {"CPU Vectors",       0x9FF8C000, 0x00001000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK},
  {"MMU PageTables",    0x9FF8D000, 0x00003000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK_XN},
  {"UEFI Stack",        0x9FF90000, 0x00040000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK_XN},
  {"RAM Partition",     0x9FFD0000, 0x00027000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN},
  {"Log Buffer",        0x9FFF7000, 0x00008000, AddMem, SYS_MEM, SYS_MEM_CAP, RtData, WRITE_BACK_XN},
  {"Info Blk",          0x9FFFF000, 0x00001000, AddMem, SYS_MEM, SYS_MEM_CAP, RtData, WRITE_BACK_XN},
  {"Kernel",            0xA0000000, 0x10000000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, WRITE_BACK_XN},
  {"DXE Heap",          0xB0000000, 0x04500000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN},
  {"RAM Partition",     0xB4500000, 0x05200000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN},

  // Memory Hole: 0xB9700000 -> 0xC0000000 (0x06900000)

  {"RAM Partition",     0xC0000000, 0x18800000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN},
  {"QTEE",              0xD8800000, 0x01800000, HobOnlyNoCacheSetting, MEM_RES, UNCACHEABLE, Reserv, UNCACHED_UNBUFFERED_XN},
  {"TZApps Reserved",   0xDA000000, 0x08800000, HobOnlyNoCacheSetting, MEM_RES, UNCACHEABLE, Reserv, UNCACHED_UNBUFFERED_XN},
  {"RAM Partition",     0xE2800000, 0x06E00000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN},
  {"DBI Dump",          0xE9600000, 0x00F00000, NoHob,  MMAP_IO, INITIALIZED, Conv,   UNCACHED_UNBUFFERED_XN},
  {"RAM Partition",     0xEA500000, 0x00100000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN},
  {"Display Reserved",  0xEA600000, 0x02400000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, WRITE_THROUGH_XN},

  // Other Memory Regions
  {"IMEM Base",         0x14680000, 0x00040000, NoHob,  MMAP_IO, INITIALIZED, Conv,   NS_DEVICE},
  {"IMEM Cookie Base",  0x146BF000, 0x00001000, AddDev, MMAP_IO, INITIALIZED, Conv,   NS_DEVICE},

  // Register Regions
  {"IPC_ROUTER_TOP",    0x00400000, 0x00100000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"SECURITY CONTROL",  0x00780000, 0x00007000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"QUP",               0x00800000, 0x00300000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"PRNG_CFG_PRNG",     0x010D0000, 0x00010000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"TCSR_TCSR_REGS",    0x01FC0000, 0x00030000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"PERIPH_SS",         0x08800000, 0x00200000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"USB",               0x0A600000, 0x04000000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"AOSS",              0x0B000000, 0x04000000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"TLMM_WEST",         0x0F100000, 0x00300000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"TLMM_SOUTH",        0x0F500000, 0x00300000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"TLMM_NORTH",        0x0F900000, 0x00300000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"SMMU",              0x15000000, 0x000D0000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"APSS_HM",           0x17800000, 0x00D99000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},

  // Terminator for MMU
  {"Terminator", 0, 0, 0, 0, 0, 0, 0}
};

ARM_MEMORY_REGION_DESCRIPTOR_EX*
GetDeviceMemoryMap ()
{
  return gDeviceMemoryDescriptorEx;
}