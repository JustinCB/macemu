#ifndef PPC_CPU_WRAP_H
#define PPC_CPU_WRAP_H
#include "ppc-registers.hpp"
#ifdef __cplusplus
#include "ppc-cpu.hpp"
extern "C" {
#endif
#include "OLDOPS.H"
extern regpointer c_registers;
#ifdef __cplusplus
}
regpointer make_regptr(struct powerpc_registers * regs);
static void bcctr_idiot(powerpc_cpu * cpu, uint32 op)
{
	(*(c_registers.pc)) += 4;
	bcctr(c_registers, op);
    
}
void init_c_registers(powerpc_registers & regs);
struct idiot : nv_mem_fun1_t< void, powerpc_cpu, uint32 > {
public:

    idiot()
    {
        pf = bcctr_idiot;
    }
};
idiot bcctr_cpp;

static void dozi_wrapper(powerpc_cpu * cpu, uint32 op)
{
	(*(c_registers.pc)) += 4;
	dozi(c_registers, op);
}
struct dozi_struct : nv_mem_fun1_t<void, powerpc_cpu, uint32> {
public:
	dozi_struct()
	{
		pf = dozi_wrapper;
	}
};
dozi_struct dozi_cpp;

static void maskg_wrapper(powerpc_cpu * cpu, uint32 op)
{
    (*(c_registers.pc)) += 4;
    maskg(c_registers, op);
}
struct maskg_struct : nv_mem_fun1_t<void, powerpc_cpu, uint32> {
public:
    maskg_struct()
    {
        pf = maskg_wrapper;
    }
};
maskg_struct maskg_cpp;

static void abs_wrapper(powerpc_cpu * cpu, uint32 op)
{
    (*(c_registers.pc)) += 4;
    power_opc_abs(c_registers, op);
}
struct abs_struct : nv_mem_fun1_t<void, powerpc_cpu, uint32> {
public:
    abs_struct()
    {
        pf = abs_wrapper;
    }
};
abs_struct abs_cpp;

static void clcs_wrapper(powerpc_cpu * cpu, uint32 op)
{
    (*(c_registers.pc)) += 4;
    power_opc_clcs(c_registers, op);
}
struct clcs_struct : nv_mem_fun1_t<void, powerpc_cpu, uint32> {
public:
    clcs_struct()
    {
        pf = clcs_wrapper;
    }
};
clcs_struct clcs_cpp;

static void doz_wrapper(powerpc_cpu * cpu, uint32 op)
{
    (*(c_registers.pc)) += 4;
    power_opc_doz(c_registers, op);
}
struct doz_struct : nv_mem_fun1_t<void, powerpc_cpu, uint32> {
public:
    doz_struct()
    {
        pf = doz_wrapper;
    }
};
doz_struct doz_cpp;

static void lscbx_wrapper(powerpc_cpu * cpu, uint32 op)
{
	(*(c_registers.pc)) += 4;
	power_opc_lscbx(c_registers, op);
}
struct lscbx_struct : nv_mem_fun1_t<void, powerpc_cpu, uint32> {
public:
	lscbx_struct()
	{
		pf = lscbx_wrapper;
	}
};
lscbx_struct lscbx_cpp;

static void maskir_wrapper(powerpc_cpu * cpu, uint32 op)
{
	(*(c_registers.pc)) += 4;
	power_opc_maskir(c_registers, op);
}
struct maskir_struct : nv_mem_fun1_t<void, powerpc_cpu, uint32> {
public:
	maskir_struct()
	{
		pf = maskir_wrapper;
	}
};
maskir_struct maskir_cpp;

static void nabs_wrapper(powerpc_cpu * cpu, uint32 op)
{
    (*(c_registers.pc)) += 4;
    power_opc_nabs(c_registers, op);
}
struct nabs_struct : nv_mem_fun1_t<void, powerpc_cpu, uint32> {
public:
    nabs_struct()
    {
        pf = nabs_wrapper;
    }
};
nabs_struct nabs_cpp;

static void rlmi_wrapper(powerpc_cpu * cpu, uint32 op)
{
    (*(c_registers.pc)) += 4;
    power_opc_rlmi(c_registers, op);
}
struct rlmi_struct : nv_mem_fun1_t<void, powerpc_cpu, uint32> {
public:
    rlmi_struct()
    {
        pf = rlmi_wrapper;
    }
};
rlmi_struct rlmi_cpp;

static void rrib_wrapper(powerpc_cpu * cpu, uint32 op)
{
    (*(c_registers.pc)) += 4;
    power_opc_rrib(c_registers, op);
}
struct rrib_struct : nv_mem_fun1_t<void, powerpc_cpu, uint32> {
public:
    rrib_struct()
    {
        pf = rrib_wrapper;
    }
};
rrib_struct rrib_cpp;

static void div_wrapper(powerpc_cpu * cpu, uint32 op)
{
    (*(c_registers.pc)) += 4;
    power_opc_div(c_registers, op);
}
struct div_struct : nv_mem_fun1_t<void, powerpc_cpu, uint32> {
public:
    div_struct()
    {
        pf = div_wrapper;
    }
};
div_struct div_cpp;

static void divs_wrapper(powerpc_cpu * cpu, uint32 op)
{
	(*(c_registers.pc)) += 4;
	power_opc_divs(c_registers, op);
}
struct divs_struct : nv_mem_fun1_t<void, powerpc_cpu, uint32> {
public:
	divs_struct()
	{
		pf = divs_wrapper;
	}
};
divs_struct divs_cpp;

static void mul_wrapper(powerpc_cpu * cpu, uint32 op)
{
	(*(c_registers.pc)) += 4;
	power_opc_mul(c_registers, op);
}
struct mul_struct : nv_mem_fun1_t<void, powerpc_cpu, uint32> {
public:
	mul_struct()
	{
		pf = mul_wrapper;
	}
};
mul_struct mul_cpp;

static void sle_wrapper(powerpc_cpu * cpu, uint32 op)
{
	(*(c_registers.pc)) += 4;
	power_opc_sle(c_registers, op);
}
struct sle_struct : nv_mem_fun1_t<void, powerpc_cpu, uint32> {
public:
	sle_struct()
	{
		pf = sle_wrapper;
	}
};
sle_struct sle_cpp;

static void sleq_wrapper(powerpc_cpu * cpu, uint32 op)
{
    (*(c_registers.pc)) += 4;
    power_opc_sleq(c_registers, op);
}
struct sleq_struct : nv_mem_fun1_t<void, powerpc_cpu, uint32> {
public:
    sleq_struct()
    {
        pf = sleq_wrapper;
    }
};
sleq_struct sleq_cpp;

static void sliq_wrapper(powerpc_cpu * cpu, uint32 op)
{
    (*(c_registers.pc)) += 4;
    power_opc_sliq(c_registers, op);
}
struct sliq_struct : nv_mem_fun1_t<void, powerpc_cpu, uint32> {
public:
    sliq_struct()
    {
        pf = sliq_wrapper;
    }
};
sliq_struct sliq_cpp;

static void sllq_wrapper(powerpc_cpu * cpu, uint32 op)
{
    (*(c_registers.pc)) += 4;
    power_opc_sllq(c_registers, op);
}
struct sllq_struct : nv_mem_fun1_t<void, powerpc_cpu, uint32> {
public:
    sllq_struct()
    {
        pf = sllq_wrapper;
    }
};
struct sllq_struct sllq_cpp;

static void slq_wrapper(powerpc_cpu * cpu, uint32 op)
{
    (*(c_registers.pc)) += 4;
    power_opc_slq(c_registers, op);
}
struct slq_struct : nv_mem_fun1_t<void, powerpc_cpu, uint32> {
public:
    slq_struct()
    {
        pf = slq_wrapper;
    }
};
slq_struct slq_cpp;

static void sraiq_wrapper(powerpc_cpu * cpu, uint32 op)
{
    (*(c_registers.pc)) += 4;
    power_opc_sraiq(c_registers, op);
}
struct sraiq_struct : nv_mem_fun1_t<void, powerpc_cpu, uint32> {
public:
    sraiq_struct()
    {
        pf = sraiq_wrapper;
    }
};
sraiq_struct sraiq_cpp;

static void sraq_wrapper(powerpc_cpu * cpu, uint32 op)
{
    (*(c_registers.pc)) += 4;
    power_opc_sraq(c_registers, op);
}
struct sraq_struct : nv_mem_fun1_t<void, powerpc_cpu, uint32> {
public:
    sraq_struct()
    {
        pf = sraq_wrapper;
    }
};
sraq_struct sraq_cpp;

static void sre_wrapper(powerpc_cpu * cpu, uint32 op)
{
    (*(c_registers.pc)) += 4;
    power_opc_sraq(c_registers, op);
}
struct sre_struct : nv_mem_fun1_t<void, powerpc_cpu, uint32> {
public:
    sre_struct()
    {
        pf = sre_wrapper;
    }
};
sre_struct sre_cpp;

static void srea_wrapper(powerpc_cpu * cpu, uint32 op)
{
    (*(c_registers.pc)) += 4;
    power_opc_sraq(c_registers, op);
}
struct srea_struct : nv_mem_fun1_t<void, powerpc_cpu, uint32> {
public:
    srea_struct()
    {
        pf = srea_wrapper;
    }
};
srea_struct srea_cpp;

static void sreq_wrapper(powerpc_cpu * cpu, uint32 op)
{
    (*(c_registers.pc)) += 4;
    power_opc_sreq(c_registers, op);
}
struct sreq_struct : nv_mem_fun1_t<void, powerpc_cpu, uint32> {
public:
    sreq_struct()
    {
        pf = sreq_wrapper;
    }
};
sreq_struct sreq_cpp;

static void srliq_sriq_wrapper(powerpc_cpu * cpu, uint32 op)
{
	(*(c_registers.pc)) += 4;
	power_opc_srliq_sriq(c_registers, op);
}
struct srliq_sriq_struct : nv_mem_fun1_t<void, powerpc_cpu, uint32> {
public:
	srliq_sriq_struct()
	{
		pf = srliq_sriq_wrapper;
	}
};
srliq_sriq_struct sriq_cpp;
#define srliq_cpp sriq_cpp

static void srlq_wrapper(powerpc_cpu * cpu, uint32 op)
{
	(*(c_registers.pc)) += 4;
	power_opc_srlq(c_registers, op);
}
struct srlq_struct : nv_mem_fun1_t<void, powerpc_cpu, uint32> {
public:
	srlq_struct()
	{
		pf = srlq_wrapper;
	}
};
srlq_struct srlq_cpp;

static void srq_wrapper(powerpc_cpu * cpu, uint32 op)
{
	(*(c_registers.pc)) += 4;
	power_opc_srq(c_registers, op);
}
struct srq_struct : nv_mem_fun1_t<void, powerpc_cpu, uint32> {
public:
	srq_struct()
	{
		pf = srq_wrapper;
	}
};
srq_struct srq_cpp;
#endif
#endif
