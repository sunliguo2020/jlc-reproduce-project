#ifndef __STM32F0XX_TSC_BITS_H
#define __STM32F0XX_TSC_BITS_H

/*
 * STM32F072 TSC register bit definitions.
 * Intended to supplement the legacy STM32F0 Standard Peripheral Library
 * stm32f0xx.h, which already defines TSC_TypeDef/TSC/TSC_BASE but omits
 * the TSC register bit-mask macros.
 */

#include "stm32f0xx.h"

/* TSC_CR --------------------------------------------------------------- */
#define TSC_CR_TSCE_Pos             (0U)
#define TSC_CR_TSCE_Msk             (0x1UL << TSC_CR_TSCE_Pos)
#define TSC_CR_TSCE                 TSC_CR_TSCE_Msk
#define TSC_CR_START_Pos            (1U)
#define TSC_CR_START_Msk            (0x1UL << TSC_CR_START_Pos)
#define TSC_CR_START                TSC_CR_START_Msk
#define TSC_CR_AM_Pos               (2U)
#define TSC_CR_AM_Msk               (0x1UL << TSC_CR_AM_Pos)
#define TSC_CR_AM                   TSC_CR_AM_Msk
#define TSC_CR_SYNCPOL_Pos          (3U)
#define TSC_CR_SYNCPOL_Msk          (0x1UL << TSC_CR_SYNCPOL_Pos)
#define TSC_CR_SYNCPOL              TSC_CR_SYNCPOL_Msk
#define TSC_CR_IODEF_Pos            (4U)
#define TSC_CR_IODEF_Msk            (0x1UL << TSC_CR_IODEF_Pos)
#define TSC_CR_IODEF                TSC_CR_IODEF_Msk
#define TSC_CR_MCV_Pos              (5U)
#define TSC_CR_MCV_Msk              (0x7UL << TSC_CR_MCV_Pos)
#define TSC_CR_MCV                  TSC_CR_MCV_Msk
#define TSC_CR_MCV_0                (0x1UL << TSC_CR_MCV_Pos)
#define TSC_CR_MCV_1                (0x2UL << TSC_CR_MCV_Pos)
#define TSC_CR_MCV_2                (0x4UL << TSC_CR_MCV_Pos)
#define TSC_CR_PGPSC_Pos            (12U)
#define TSC_CR_PGPSC_Msk            (0x7UL << TSC_CR_PGPSC_Pos)
#define TSC_CR_PGPSC                TSC_CR_PGPSC_Msk
#define TSC_CR_PGPSC_0              (0x1UL << TSC_CR_PGPSC_Pos)
#define TSC_CR_PGPSC_1              (0x2UL << TSC_CR_PGPSC_Pos)
#define TSC_CR_PGPSC_2              (0x4UL << TSC_CR_PGPSC_Pos)
#define TSC_CR_SSPSC_Pos            (15U)
#define TSC_CR_SSPSC_Msk            (0x1UL << TSC_CR_SSPSC_Pos)
#define TSC_CR_SSPSC                TSC_CR_SSPSC_Msk
#define TSC_CR_SSE_Pos              (16U)
#define TSC_CR_SSE_Msk              (0x1UL << TSC_CR_SSE_Pos)
#define TSC_CR_SSE                  TSC_CR_SSE_Msk
#define TSC_CR_SSD_Pos              (17U)
#define TSC_CR_SSD_Msk              (0x7FUL << TSC_CR_SSD_Pos)
#define TSC_CR_SSD                  TSC_CR_SSD_Msk
#define TSC_CR_SSD_0                (0x1UL << TSC_CR_SSD_Pos)
#define TSC_CR_SSD_1                (0x2UL << TSC_CR_SSD_Pos)
#define TSC_CR_SSD_2                (0x4UL << TSC_CR_SSD_Pos)
#define TSC_CR_SSD_3                (0x8UL << TSC_CR_SSD_Pos)
#define TSC_CR_SSD_4                (0x10UL << TSC_CR_SSD_Pos)
#define TSC_CR_SSD_5                (0x20UL << TSC_CR_SSD_Pos)
#define TSC_CR_SSD_6                (0x40UL << TSC_CR_SSD_Pos)
#define TSC_CR_CTPL_Pos             (24U)
#define TSC_CR_CTPL_Msk             (0xFUL << TSC_CR_CTPL_Pos)
#define TSC_CR_CTPL                 TSC_CR_CTPL_Msk
#define TSC_CR_CTPL_0               (0x1UL << TSC_CR_CTPL_Pos)
#define TSC_CR_CTPL_1               (0x2UL << TSC_CR_CTPL_Pos)
#define TSC_CR_CTPL_2               (0x4UL << TSC_CR_CTPL_Pos)
#define TSC_CR_CTPL_3               (0x8UL << TSC_CR_CTPL_Pos)
#define TSC_CR_CTPH_Pos             (28U)
#define TSC_CR_CTPH_Msk             (0xFUL << TSC_CR_CTPH_Pos)
#define TSC_CR_CTPH                 TSC_CR_CTPH_Msk
#define TSC_CR_CTPH_0               (0x1UL << TSC_CR_CTPH_Pos)
#define TSC_CR_CTPH_1               (0x2UL << TSC_CR_CTPH_Pos)
#define TSC_CR_CTPH_2               (0x4UL << TSC_CR_CTPH_Pos)
#define TSC_CR_CTPH_3               (0x8UL << TSC_CR_CTPH_Pos)

/* TSC_IER -------------------------------------------------------------- */
#define TSC_IER_EOAIE_Pos           (0U)
#define TSC_IER_EOAIE_Msk           (0x1UL << TSC_IER_EOAIE_Pos)
#define TSC_IER_EOAIE               TSC_IER_EOAIE_Msk
#define TSC_IER_MCEIE_Pos           (1U)
#define TSC_IER_MCEIE_Msk           (0x1UL << TSC_IER_MCEIE_Pos)
#define TSC_IER_MCEIE               TSC_IER_MCEIE_Msk

/* TSC_ICR -------------------------------------------------------------- */
#define TSC_ICR_EOAIC_Pos           (0U)
#define TSC_ICR_EOAIC_Msk           (0x1UL << TSC_ICR_EOAIC_Pos)
#define TSC_ICR_EOAIC               TSC_ICR_EOAIC_Msk
#define TSC_ICR_MCEIC_Pos           (1U)
#define TSC_ICR_MCEIC_Msk           (0x1UL << TSC_ICR_MCEIC_Pos)
#define TSC_ICR_MCEIC               TSC_ICR_MCEIC_Msk

/* TSC_ISR -------------------------------------------------------------- */
#define TSC_ISR_EOAF_Pos            (0U)
#define TSC_ISR_EOAF_Msk            (0x1UL << TSC_ISR_EOAF_Pos)
#define TSC_ISR_EOAF                TSC_ISR_EOAF_Msk
#define TSC_ISR_MCEF_Pos            (1U)
#define TSC_ISR_MCEF_Msk            (0x1UL << TSC_ISR_MCEF_Pos)
#define TSC_ISR_MCEF                TSC_ISR_MCEF_Msk

/* TSC_IOHCR ------------------------------------------------------------ */
#define TSC_IOHCR_G1_IO1_Pos        (0U)
#define TSC_IOHCR_G1_IO1_Msk        (0x1UL << TSC_IOHCR_G1_IO1_Pos)
#define TSC_IOHCR_G1_IO1            TSC_IOHCR_G1_IO1_Msk
#define TSC_IOHCR_G1_IO2_Pos        (1U)
#define TSC_IOHCR_G1_IO2_Msk        (0x1UL << TSC_IOHCR_G1_IO2_Pos)
#define TSC_IOHCR_G1_IO2            TSC_IOHCR_G1_IO2_Msk
#define TSC_IOHCR_G1_IO3_Pos        (2U)
#define TSC_IOHCR_G1_IO3_Msk        (0x1UL << TSC_IOHCR_G1_IO3_Pos)
#define TSC_IOHCR_G1_IO3            TSC_IOHCR_G1_IO3_Msk
#define TSC_IOHCR_G1_IO4_Pos        (3U)
#define TSC_IOHCR_G1_IO4_Msk        (0x1UL << TSC_IOHCR_G1_IO4_Pos)
#define TSC_IOHCR_G1_IO4            TSC_IOHCR_G1_IO4_Msk
#define TSC_IOHCR_G2_IO1_Pos        (4U)
#define TSC_IOHCR_G2_IO1_Msk        (0x1UL << TSC_IOHCR_G2_IO1_Pos)
#define TSC_IOHCR_G2_IO1            TSC_IOHCR_G2_IO1_Msk
#define TSC_IOHCR_G2_IO2_Pos        (5U)
#define TSC_IOHCR_G2_IO2_Msk        (0x1UL << TSC_IOHCR_G2_IO2_Pos)
#define TSC_IOHCR_G2_IO2            TSC_IOHCR_G2_IO2_Msk
#define TSC_IOHCR_G2_IO3_Pos        (6U)
#define TSC_IOHCR_G2_IO3_Msk        (0x1UL << TSC_IOHCR_G2_IO3_Pos)
#define TSC_IOHCR_G2_IO3            TSC_IOHCR_G2_IO3_Msk
#define TSC_IOHCR_G2_IO4_Pos        (7U)
#define TSC_IOHCR_G2_IO4_Msk        (0x1UL << TSC_IOHCR_G2_IO4_Pos)
#define TSC_IOHCR_G2_IO4            TSC_IOHCR_G2_IO4_Msk
#define TSC_IOHCR_G3_IO1_Pos        (8U)
#define TSC_IOHCR_G3_IO1_Msk        (0x1UL << TSC_IOHCR_G3_IO1_Pos)
#define TSC_IOHCR_G3_IO1            TSC_IOHCR_G3_IO1_Msk
#define TSC_IOHCR_G3_IO2_Pos        (9U)
#define TSC_IOHCR_G3_IO2_Msk        (0x1UL << TSC_IOHCR_G3_IO2_Pos)
#define TSC_IOHCR_G3_IO2            TSC_IOHCR_G3_IO2_Msk
#define TSC_IOHCR_G3_IO3_Pos        (10U)
#define TSC_IOHCR_G3_IO3_Msk        (0x1UL << TSC_IOHCR_G3_IO3_Pos)
#define TSC_IOHCR_G3_IO3            TSC_IOHCR_G3_IO3_Msk
#define TSC_IOHCR_G3_IO4_Pos        (11U)
#define TSC_IOHCR_G3_IO4_Msk        (0x1UL << TSC_IOHCR_G3_IO4_Pos)
#define TSC_IOHCR_G3_IO4            TSC_IOHCR_G3_IO4_Msk
#define TSC_IOHCR_G4_IO1_Pos        (12U)
#define TSC_IOHCR_G4_IO1_Msk        (0x1UL << TSC_IOHCR_G4_IO1_Pos)
#define TSC_IOHCR_G4_IO1            TSC_IOHCR_G4_IO1_Msk
#define TSC_IOHCR_G4_IO2_Pos        (13U)
#define TSC_IOHCR_G4_IO2_Msk        (0x1UL << TSC_IOHCR_G4_IO2_Pos)
#define TSC_IOHCR_G4_IO2            TSC_IOHCR_G4_IO2_Msk
#define TSC_IOHCR_G4_IO3_Pos        (14U)
#define TSC_IOHCR_G4_IO3_Msk        (0x1UL << TSC_IOHCR_G4_IO3_Pos)
#define TSC_IOHCR_G4_IO3            TSC_IOHCR_G4_IO3_Msk
#define TSC_IOHCR_G4_IO4_Pos        (15U)
#define TSC_IOHCR_G4_IO4_Msk        (0x1UL << TSC_IOHCR_G4_IO4_Pos)
#define TSC_IOHCR_G4_IO4            TSC_IOHCR_G4_IO4_Msk
#define TSC_IOHCR_G5_IO1_Pos        (16U)
#define TSC_IOHCR_G5_IO1_Msk        (0x1UL << TSC_IOHCR_G5_IO1_Pos)
#define TSC_IOHCR_G5_IO1            TSC_IOHCR_G5_IO1_Msk
#define TSC_IOHCR_G5_IO2_Pos        (17U)
#define TSC_IOHCR_G5_IO2_Msk        (0x1UL << TSC_IOHCR_G5_IO2_Pos)
#define TSC_IOHCR_G5_IO2            TSC_IOHCR_G5_IO2_Msk
#define TSC_IOHCR_G5_IO3_Pos        (18U)
#define TSC_IOHCR_G5_IO3_Msk        (0x1UL << TSC_IOHCR_G5_IO3_Pos)
#define TSC_IOHCR_G5_IO3            TSC_IOHCR_G5_IO3_Msk
#define TSC_IOHCR_G5_IO4_Pos        (19U)
#define TSC_IOHCR_G5_IO4_Msk        (0x1UL << TSC_IOHCR_G5_IO4_Pos)
#define TSC_IOHCR_G5_IO4            TSC_IOHCR_G5_IO4_Msk
#define TSC_IOHCR_G6_IO1_Pos        (20U)
#define TSC_IOHCR_G6_IO1_Msk        (0x1UL << TSC_IOHCR_G6_IO1_Pos)
#define TSC_IOHCR_G6_IO1            TSC_IOHCR_G6_IO1_Msk
#define TSC_IOHCR_G6_IO2_Pos        (21U)
#define TSC_IOHCR_G6_IO2_Msk        (0x1UL << TSC_IOHCR_G6_IO2_Pos)
#define TSC_IOHCR_G6_IO2            TSC_IOHCR_G6_IO2_Msk
#define TSC_IOHCR_G6_IO3_Pos        (22U)
#define TSC_IOHCR_G6_IO3_Msk        (0x1UL << TSC_IOHCR_G6_IO3_Pos)
#define TSC_IOHCR_G6_IO3            TSC_IOHCR_G6_IO3_Msk
#define TSC_IOHCR_G6_IO4_Pos        (23U)
#define TSC_IOHCR_G6_IO4_Msk        (0x1UL << TSC_IOHCR_G6_IO4_Pos)
#define TSC_IOHCR_G6_IO4            TSC_IOHCR_G6_IO4_Msk
#define TSC_IOHCR_G7_IO1_Pos        (24U)
#define TSC_IOHCR_G7_IO1_Msk        (0x1UL << TSC_IOHCR_G7_IO1_Pos)
#define TSC_IOHCR_G7_IO1            TSC_IOHCR_G7_IO1_Msk
#define TSC_IOHCR_G7_IO2_Pos        (25U)
#define TSC_IOHCR_G7_IO2_Msk        (0x1UL << TSC_IOHCR_G7_IO2_Pos)
#define TSC_IOHCR_G7_IO2            TSC_IOHCR_G7_IO2_Msk
#define TSC_IOHCR_G7_IO3_Pos        (26U)
#define TSC_IOHCR_G7_IO3_Msk        (0x1UL << TSC_IOHCR_G7_IO3_Pos)
#define TSC_IOHCR_G7_IO3            TSC_IOHCR_G7_IO3_Msk
#define TSC_IOHCR_G7_IO4_Pos        (27U)
#define TSC_IOHCR_G7_IO4_Msk        (0x1UL << TSC_IOHCR_G7_IO4_Pos)
#define TSC_IOHCR_G7_IO4           TSC_IOHCR_G7_IO4_Msk
#define TSC_IOHCR_G8_IO1_Pos        (28U)
#define TSC_IOHCR_G8_IO1_Msk        (0x1UL << TSC_IOHCR_G8_IO1_Pos)
#define TSC_IOHCR_G8_IO1            TSC_IOHCR_G8_IO1_Msk
#define TSC_IOHCR_G8_IO2_Pos        (29U)
#define TSC_IOHCR_G8_IO2_Msk        (0x1UL << TSC_IOHCR_G8_IO2_Pos)
#define TSC_IOHCR_G8_IO2            TSC_IOHCR_G8_IO2_Msk
#define TSC_IOHCR_G8_IO3_Pos        (30U)
#define TSC_IOHCR_G8_IO3_Msk        (0x1UL << TSC_IOHCR_G8_IO3_Pos)
#define TSC_IOHCR_G8_IO3            TSC_IOHCR_G8_IO3_Msk
#define TSC_IOHCR_G8_IO4_Pos        (31U)
#define TSC_IOHCR_G8_IO4_Msk        (0x1UL << TSC_IOHCR_G8_IO4_Pos)
#define TSC_IOHCR_G8_IO4            TSC_IOHCR_G8_IO4_Msk

/* TSC_IOASCR ------------------------------------------------------------ */
#define TSC_IOASCR_G1_IO1_Pos       (0U)
#define TSC_IOASCR_G1_IO1_Msk       (0x1UL << TSC_IOASCR_G1_IO1_Pos)
#define TSC_IOASCR_G1_IO1           TSC_IOASCR_G1_IO1_Msk
#define TSC_IOASCR_G1_IO2_Pos       (1U)
#define TSC_IOASCR_G1_IO2_Msk       (0x1UL << TSC_IOASCR_G1_IO2_Pos)
#define TSC_IOASCR_G1_IO2           TSC_IOASCR_G1_IO2_Msk
#define TSC_IOASCR_G1_IO3_Pos       (2U)
#define TSC_IOASCR_G1_IO3_Msk       (0x1UL << TSC_IOASCR_G1_IO3_Pos)
#define TSC_IOASCR_G1_IO3           TSC_IOASCR_G1_IO3_Msk
#define TSC_IOASCR_G1_IO4_Pos       (3U)
#define TSC_IOASCR_G1_IO4_Msk       (0x1UL << TSC_IOASCR_G1_IO4_Pos)
#define TSC_IOASCR_G1_IO4           TSC_IOASCR_G1_IO4_Msk
#define TSC_IOASCR_G2_IO1_Pos       (4U)
#define TSC_IOASCR_G2_IO1_Msk       (0x1UL << TSC_IOASCR_G2_IO1_Pos)
#define TSC_IOASCR_G2_IO1           TSC_IOASCR_G2_IO1_Msk
#define TSC_IOASCR_G2_IO2_Pos       (5U)
#define TSC_IOASCR_G2_IO2_Msk       (0x1UL << TSC_IOASCR_G2_IO2_Pos)
#define TSC_IOASCR_G2_IO2           TSC_IOASCR_G2_IO2_Msk
#define TSC_IOASCR_G2_IO3_Pos       (6U)
#define TSC_IOASCR_G2_IO3_Msk       (0x1UL << TSC_IOASCR_G2_IO3_Pos)
#define TSC_IOASCR_G2_IO3           TSC_IOASCR_G2_IO3_Msk
#define TSC_IOASCR_G2_IO4_Pos       (7U)
#define TSC_IOASCR_G2_IO4_Msk       (0x1UL << TSC_IOASCR_G2_IO4_Pos)
#define TSC_IOASCR_G2_IO4           TSC_IOASCR_G2_IO4_Msk
#define TSC_IOASCR_G3_IO1_Pos       (8U)
#define TSC_IOASCR_G3_IO1_Msk       (0x1UL << TSC_IOASCR_G3_IO1_Pos)
#define TSC_IOASCR_G3_IO1           TSC_IOASCR_G3_IO1_Msk
#define TSC_IOASCR_G3_IO2_Pos       (9U)
#define TSC_IOASCR_G3_IO2_Msk       (0x1UL << TSC_IOASCR_G3_IO2_Pos)
#define TSC_IOASCR_G3_IO2           TSC_IOASCR_G3_IO2_Msk
#define TSC_IOASCR_G3_IO3_Pos       (10U)
#define TSC_IOASCR_G3_IO3_Msk       (0x1UL << TSC_IOASCR_G3_IO3_Pos)
#define TSC_IOASCR_G3_IO3           TSC_IOASCR_G3_IO3_Msk
#define TSC_IOASCR_G3_IO4_Pos       (11U)
#define TSC_IOASCR_G3_IO4_Msk       (0x1UL << TSC_IOASCR_G3_IO4_Pos)
#define TSC_IOASCR_G3_IO4           TSC_IOASCR_G3_IO4_Msk
#define TSC_IOASCR_G4_IO1_Pos       (12U)
#define TSC_IOASCR_G4_IO1_Msk       (0x1UL << TSC_IOASCR_G4_IO1_Pos)
#define TSC_IOASCR_G4_IO1           TSC_IOASCR_G4_IO1_Msk
#define TSC_IOASCR_G4_IO2_Pos       (13U)
#define TSC_IOASCR_G4_IO2_Msk       (0x1UL << TSC_IOASCR_G4_IO2_Pos)
#define TSC_IOASCR_G4_IO2           TSC_IOASCR_G4_IO2_Msk
#define TSC_IOASCR_G4_IO3_Pos       (14U)
#define TSC_IOASCR_G4_IO3_Msk       (0x1UL << TSC_IOASCR_G4_IO3_Pos)
#define TSC_IOASCR_G4_IO3           TSC_IOASCR_G4_IO3_Msk
#define TSC_IOASCR_G4_IO4_Pos       (15U)
#define TSC_IOASCR_G4_IO4_Msk       (0x1UL << TSC_IOASCR_G4_IO4_Pos)
#define TSC_IOASCR_G4_IO4           TSC_IOASCR_G4_IO4_Msk
#define TSC_IOASCR_G5_IO1_Pos       (16U)
#define TSC_IOASCR_G5_IO1_Msk       (0x1UL << TSC_IOASCR_G5_IO1_Pos)
#define TSC_IOASCR_G5_IO1           TSC_IOASCR_G5_IO1_Msk
#define TSC_IOASCR_G5_IO2_Pos       (17U)
#define TSC_IOASCR_G5_IO2_Msk       (0x1UL << TSC_IOASCR_G5_IO2_Pos)
#define TSC_IOASCR_G5_IO2           TSC_IOASCR_G5_IO2_Msk
#define TSC_IOASCR_G5_IO3_Pos       (18U)
#define TSC_IOASCR_G5_IO3_Msk       (0x1UL << TSC_IOASCR_G5_IO3_Pos)
#define TSC_IOASCR_G5_IO3           TSC_IOASCR_G5_IO3_Msk
#define TSC_IOASCR_G5_IO4_Pos       (19U)
#define TSC_IOASCR_G5_IO4_Msk       (0x1UL << TSC_IOASCR_G5_IO4_Pos)
#define TSC_IOASCR_G5_IO4           TSC_IOASCR_G5_IO4_Msk
#define TSC_IOASCR_G6_IO1_Pos       (20U)
#define TSC_IOASCR_G6_IO1_Msk       (0x1UL << TSC_IOASCR_G6_IO1_Pos)
#define TSC_IOASCR_G6_IO1           TSC_IOASCR_G6_IO1_Msk
#define TSC_IOASCR_G6_IO2_Pos       (21U)
#define TSC_IOASCR_G6_IO2_Msk       (0x1UL << TSC_IOASCR_G6_IO2_Pos)
#define TSC_IOASCR_G6_IO2           TSC_IOASCR_G6_IO2_Msk
#define TSC_IOASCR_G6_IO3_Pos       (22U)
#define TSC_IOASCR_G6_IO3_Msk       (0x1UL << TSC_IOASCR_G6_IO3_Pos)
#define TSC_IOASCR_G6_IO3           TSC_IOASCR_G6_IO3_Msk
#define TSC_IOASCR_G6_IO4_Pos       (23U)
#define TSC_IOASCR_G6_IO4_Msk       (0x1UL << TSC_IOASCR_G6_IO4_Pos)
#define TSC_IOASCR_G6_IO4           TSC_IOASCR_G6_IO4_Msk
#define TSC_IOASCR_G7_IO1_Pos       (24U)
#define TSC_IOASCR_G7_IO1_Msk       (0x1UL << TSC_IOASCR_G7_IO1_Pos)
#define TSC_IOASCR_G7_IO1           TSC_IOASCR_G7_IO1_Msk
#define TSC_IOASCR_G7_IO2_Pos       (25U)
#define TSC_IOASCR_G7_IO2_Msk       (0x1UL << TSC_IOASCR_G7_IO2_Pos)
#define TSC_IOASCR_G7_IO2           TSC_IOASCR_G7_IO2_Msk
#define TSC_IOASCR_G7_IO3_Pos       (26U)
#define TSC_IOASCR_G7_IO3_Msk       (0x1UL << TSC_IOASCR_G7_IO3_Pos)
#define TSC_IOASCR_G7_IO3           TSC_IOASCR_G7_IO3_Msk
#define TSC_IOASCR_G7_IO4_Pos       (27U)
#define TSC_IOASCR_G7_IO4_Msk       (0x1UL << TSC_IOASCR_G7_IO4_Pos)
#define TSC_IOASCR_G7_IO4           TSC_IOASCR_G7_IO4_Msk
#define TSC_IOASCR_G8_IO1_Pos       (28U)
#define TSC_IOASCR_G8_IO1_Msk       (0x1UL << TSC_IOASCR_G8_IO1_Pos)
#define TSC_IOASCR_G8_IO1           TSC_IOASCR_G8_IO1_Msk
#define TSC_IOASCR_G8_IO2_Pos       (29U)
#define TSC_IOASCR_G8_IO2_Msk       (0x1UL << TSC_IOASCR_G8_IO2_Pos)
#define TSC_IOASCR_G8_IO2           TSC_IOASCR_G8_IO2_Msk
#define TSC_IOASCR_G8_IO3_Pos       (30U)
#define TSC_IOASCR_G8_IO3_Msk       (0x1UL << TSC_IOASCR_G8_IO3_Pos)
#define TSC_IOASCR_G8_IO3           TSC_IOASCR_G8_IO3_Msk
#define TSC_IOASCR_G8_IO4_Pos       (31U)
#define TSC_IOASCR_G8_IO4_Msk       (0x1UL << TSC_IOASCR_G8_IO4_Pos)
#define TSC_IOASCR_G8_IO4           TSC_IOASCR_G8_IO4_Msk

/* TSC_IOSCR ------------------------------------------------------------ */
#define TSC_IOSCR_G1_IO1_Pos       (0U)
#define TSC_IOSCR_G1_IO1_Msk       (0x1UL << TSC_IOSCR_G1_IO1_Pos)
#define TSC_IOSCR_G1_IO1           TSC_IOSCR_G1_IO1_Msk
#define TSC_IOSCR_G1_IO2_Pos       (1U)
#define TSC_IOSCR_G1_IO2_Msk       (0x1UL << TSC_IOSCR_G1_IO2_Pos)
#define TSC_IOSCR_G1_IO2           TSC_IOSCR_G1_IO2_Msk
#define TSC_IOSCR_G1_IO3_Pos       (2U)
#define TSC_IOSCR_G1_IO3_Msk       (0x1UL << TSC_IOSCR_G1_IO3_Pos)
#define TSC_IOSCR_G1_IO3           TSC_IOSCR_G1_IO3_Msk
#define TSC_IOSCR_G1_IO4_Pos       (3U)
#define TSC_IOSCR_G1_IO4_Msk       (0x1UL << TSC_IOSCR_G1_IO4_Pos)
#define TSC_IOSCR_G1_IO4           TSC_IOSCR_G1_IO4_Msk
#define TSC_IOSCR_G2_IO1_Pos       (4U)
#define TSC_IOSCR_G2_IO1_Msk       (0x1UL << TSC_IOSCR_G2_IO1_Pos)
#define TSC_IOSCR_G2_IO1           TSC_IOSCR_G2_IO1_Msk
#define TSC_IOSCR_G2_IO2_Pos       (5U)
#define TSC_IOSCR_G2_IO2_Msk       (0x1UL << TSC_IOSCR_G2_IO2_Pos)
#define TSC_IOSCR_G2_IO2           TSC_IOSCR_G2_IO2_Msk
#define TSC_IOSCR_G2_IO3_Pos       (6U)
#define TSC_IOSCR_G2_IO3_Msk       (0x1UL << TSC_IOSCR_G2_IO3_Pos)
#define TSC_IOSCR_G2_IO3           TSC_IOSCR_G2_IO3_Msk
#define TSC_IOSCR_G2_IO4_Pos       (7U)
#define TSC_IOSCR_G2_IO4_Msk       (0x1UL << TSC_IOSCR_G2_IO4_Pos)
#define TSC_IOSCR_G2_IO4           TSC_IOSCR_G2_IO4_Msk
#define TSC_IOSCR_G3_IO1_Pos       (8U)
#define TSC_IOSCR_G3_IO1_Msk       (0x1UL << TSC_IOSCR_G3_IO1_Pos)
#define TSC_IOSCR_G3_IO1           TSC_IOSCR_G3_IO1_Msk
#define TSC_IOSCR_G3_IO2_Pos       (9U)
#define TSC_IOSCR_G3_IO2_Msk       (0x1UL << TSC_IOSCR_G3_IO2_Pos)
#define TSC_IOSCR_G3_IO2           TSC_IOSCR_G3_IO2_Msk
#define TSC_IOSCR_G3_IO3_Pos       (10U)
#define TSC_IOSCR_G3_IO3_Msk       (0x1UL << TSC_IOSCR_G3_IO3_Pos)
#define TSC_IOSCR_G3_IO3           TSC_IOSCR_G3_IO3_Msk
#define TSC_IOSCR_G3_IO4_Pos       (11U)
#define TSC_IOSCR_G3_IO4_Msk       (0x1UL << TSC_IOSCR_G3_IO4_Pos)
#define TSC_IOSCR_G3_IO4           TSC_IOSCR_G3_IO4_Msk
#define TSC_IOSCR_G4_IO1_Pos       (12U)
#define TSC_IOSCR_G4_IO1_Msk       (0x1UL << TSC_IOSCR_G4_IO1_Pos)
#define TSC_IOSCR_G4_IO1           TSC_IOSCR_G4_IO1_Msk
#define TSC_IOSCR_G4_IO2_Pos       (13U)
#define TSC_IOSCR_G4_IO2_Msk       (0x1UL << TSC_IOSCR_G4_IO2_Pos)
#define TSC_IOSCR_G4_IO2           TSC_IOSCR_G4_IO2_Msk
#define TSC_IOSCR_G4_IO3_Pos       (14U)
#define TSC_IOSCR_G4_IO3_Msk       (0x1UL << TSC_IOSCR_G4_IO3_Pos)
#define TSC_IOSCR_G4_IO3           TSC_IOSCR_G4_IO3_Msk
#define TSC_IOSCR_G4_IO4_Pos       (15U)
#define TSC_IOSCR_G4_IO4_Msk       (0x1UL << TSC_IOSCR_G4_IO4_Pos)
#define TSC_IOSCR_G4_IO4           TSC_IOSCR_G4_IO4_Msk
#define TSC_IOSCR_G5_IO1_Pos       (16U)
#define TSC_IOSCR_G5_IO1_Msk       (0x1UL << TSC_IOSCR_G5_IO1_Pos)
#define TSC_IOSCR_G5_IO1           TSC_IOSCR_G5_IO1_Msk
#define TSC_IOSCR_G5_IO2_Pos       (17U)
#define TSC_IOSCR_G5_IO2_Msk       (0x1UL << TSC_IOSCR_G5_IO2_Pos)
#define TSC_IOSCR_G5_IO2           TSC_IOSCR_G5_IO2_Msk
#define TSC_IOSCR_G5_IO3_Pos       (18U)
#define TSC_IOSCR_G5_IO3_Msk       (0x1UL << TSC_IOSCR_G5_IO3_Pos)
#define TSC_IOSCR_G5_IO3           TSC_IOSCR_G5_IO3_Msk
#define TSC_IOSCR_G5_IO4_Pos       (19U)
#define TSC_IOSCR_G5_IO4_Msk       (0x1UL << TSC_IOSCR_G5_IO4_Pos)
#define TSC_IOSCR_G5_IO4           TSC_IOSCR_G5_IO4_Msk
#define TSC_IOSCR_G6_IO1_Pos       (20U)
#define TSC_IOSCR_G6_IO1_Msk       (0x1UL << TSC_IOSCR_G6_IO1_Pos)
#define TSC_IOSCR_G6_IO1           TSC_IOSCR_G6_IO1_Msk
#define TSC_IOSCR_G6_IO2_Pos       (21U)
#define TSC_IOSCR_G6_IO2_Msk       (0x1UL << TSC_IOSCR_G6_IO2_Pos)
#define TSC_IOSCR_G6_IO2           TSC_IOSCR_G6_IO2_Msk
#define TSC_IOSCR_G6_IO3_Pos       (22U)
#define TSC_IOSCR_G6_IO3_Msk       (0x1UL << TSC_IOSCR_G6_IO3_Pos)
#define TSC_IOSCR_G6_IO3           TSC_IOSCR_G6_IO3_Msk
#define TSC_IOSCR_G6_IO4_Pos       (23U)
#define TSC_IOSCR_G6_IO4_Msk       (0x1UL << TSC_IOSCR_G6_IO4_Pos)
#define TSC_IOSCR_G6_IO4           TSC_IOSCR_G6_IO4_Msk
#define TSC_IOSCR_G7_IO1_Pos       (24U)
#define TSC_IOSCR_G7_IO1_Msk       (0x1UL << TSC_IOSCR_G7_IO1_Pos)
#define TSC_IOSCR_G7_IO1           TSC_IOSCR_G7_IO1_Msk
#define TSC_IOSCR_G7_IO2_Pos       (25U)
#define TSC_IOSCR_G7_IO2_Msk       (0x1UL << TSC_IOSCR_G7_IO2_Pos)
#define TSC_IOSCR_G7_IO2           TSC_IOSCR_G7_IO2_Msk
#define TSC_IOSCR_G7_IO3_Pos       (26U)
#define TSC_IOSCR_G7_IO3_Msk       (0x1UL << TSC_IOSCR_G7_IO3_Pos)
#define TSC_IOSCR_G7_IO3           TSC_IOSCR_G7_IO3_Msk
#define TSC_IOSCR_G7_IO4_Pos       (27U)
#define TSC_IOSCR_G7_IO4_Msk       (0x1UL << TSC_IOSCR_G7_IO4_Pos)
#define TSC_IOSCR_G7_IO4           TSC_IOSCR_G7_IO4_Msk
#define TSC_IOSCR_G8_IO1_Pos       (28U)
#define TSC_IOSCR_G8_IO1_Msk       (0x1UL << TSC_IOSCR_G8_IO1_Pos)
#define TSC_IOSCR_G8_IO1           TSC_IOSCR_G8_IO1_Msk
#define TSC_IOSCR_G8_IO2_Pos       (29U)
#define TSC_IOSCR_G8_IO2_Msk       (0x1UL << TSC_IOSCR_G8_IO2_Pos)
#define TSC_IOSCR_G8_IO2           TSC_IOSCR_G8_IO2_Msk
#define TSC_IOSCR_G8_IO3_Pos       (30U)
#define TSC_IOSCR_G8_IO3_Msk       (0x1UL << TSC_IOSCR_G8_IO3_Pos)
#define TSC_IOSCR_G8_IO3           TSC_IOSCR_G8_IO3_Msk
#define TSC_IOSCR_G8_IO4_Pos       (31U)
#define TSC_IOSCR_G8_IO4_Msk       (0x1UL << TSC_IOSCR_G8_IO4_Pos)
#define TSC_IOSCR_G8_IO4           TSC_IOSCR_G8_IO4_Msk

/* TSC_IOCCR ------------------------------------------------------------ */
#define TSC_IOCCR_G1_IO1_Pos       (0U)
#define TSC_IOCCR_G1_IO1_Msk       (0x1UL << TSC_IOCCR_G1_IO1_Pos)
#define TSC_IOCCR_G1_IO1           TSC_IOCCR_G1_IO1_Msk
#define TSC_IOCCR_G1_IO2_Pos       (1U)
#define TSC_IOCCR_G1_IO2_Msk       (0x1UL << TSC_IOCCR_G1_IO2_Pos)
#define TSC_IOCCR_G1_IO2           TSC_IOCCR_G1_IO2_Msk
#define TSC_IOCCR_G1_IO3_Pos       (2U)
#define TSC_IOCCR_G1_IO3_Msk       (0x1UL << TSC_IOCCR_G1_IO3_Pos)
#define TSC_IOCCR_G1_IO3           TSC_IOCCR_G1_IO3_Msk
#define TSC_IOCCR_G1_IO4_Pos       (3U)
#define TSC_IOCCR_G1_IO4_Msk       (0x1UL << TSC_IOCCR_G1_IO4_Pos)
#define TSC_IOCCR_G1_IO4           TSC_IOCCR_G1_IO4_Msk
#define TSC_IOCCR_G2_IO1_Pos       (4U)
#define TSC_IOCCR_G2_IO1_Msk       (0x1UL << TSC_IOCCR_G2_IO1_Pos)
#define TSC_IOCCR_G2_IO1           TSC_IOCCR_G2_IO1_Msk
#define TSC_IOCCR_G2_IO2_Pos       (5U)
#define TSC_IOCCR_G2_IO2_Msk       (0x1UL << TSC_IOCCR_G2_IO2_Pos)
#define TSC_IOCCR_G2_IO2           TSC_IOCCR_G2_IO2_Msk
#define TSC_IOCCR_G2_IO3_Pos       (6U)
#define TSC_IOCCR_G2_IO3_Msk       (0x1UL << TSC_IOCCR_G2_IO3_Pos)
#define TSC_IOCCR_G2_IO3           TSC_IOCCR_G2_IO3_Msk
#define TSC_IOCCR_G2_IO4_Pos       (7U)
#define TSC_IOCCR_G2_IO4_Msk       (0x1UL << TSC_IOCCR_G2_IO4_Pos)
#define TSC_IOCCR_G2_IO4           TSC_IOCCR_G2_IO4_Msk
#define TSC_IOCCR_G3_IO1_Pos       (8U)
#define TSC_IOCCR_G3_IO1_Msk       (0x1UL << TSC_IOCCR_G3_IO1_Pos)
#define TSC_IOCCR_G3_IO1           TSC_IOCCR_G3_IO1_Msk
#define TSC_IOCCR_G3_IO2_Pos       (9U)
#define TSC_IOCCR_G3_IO2_Msk       (0x1UL << TSC_IOCCR_G3_IO2_Pos)
#define TSC_IOCCR_G3_IO2           TSC_IOCCR_G3_IO2_Msk
#define TSC_IOCCR_G3_IO3_Pos       (10U)
#define TSC_IOCCR_G3_IO3_Msk       (0x1UL << TSC_IOCCR_G3_IO3_Pos)
#define TSC_IOCCR_G3_IO3           TSC_IOCCR_G3_IO3_Msk
#define TSC_IOCCR_G3_IO4_Pos       (11U)
#define TSC_IOCCR_G3_IO4_Msk       (0x1UL << TSC_IOCCR_G3_IO4_Pos)
#define TSC_IOCCR_G3_IO4           TSC_IOCCR_G3_IO4_Msk
#define TSC_IOCCR_G4_IO1_Pos       (12U)
#define TSC_IOCCR_G4_IO1_Msk       (0x1UL << TSC_IOCCR_G4_IO1_Pos)
#define TSC_IOCCR_G4_IO1           TSC_IOCCR_G4_IO1_Msk
#define TSC_IOCCR_G4_IO2_Pos       (13U)
#define TSC_IOCCR_G4_IO2_Msk       (0x1UL << TSC_IOCCR_G4_IO2_Pos)
#define TSC_IOCCR_G4_IO2           TSC_IOCCR_G4_IO2_Msk
#define TSC_IOCCR_G4_IO3_Pos       (14U)
#define TSC_IOCCR_G4_IO3_Msk       (0x1UL << TSC_IOCCR_G4_IO3_Pos)
#define TSC_IOCCR_G4_IO3           TSC_IOCCR_G4_IO3_Msk
#define TSC_IOCCR_G4_IO4_Pos       (15U)
#define TSC_IOCCR_G4_IO4_Msk       (0x1UL << TSC_IOCCR_G4_IO4_Pos)
#define TSC_IOCCR_G4_IO4           TSC_IOCCR_G4_IO4_Msk
#define TSC_IOCCR_G5_IO1_Pos       (16U)
#define TSC_IOCCR_G5_IO1_Msk       (0x1UL << TSC_IOCCR_G5_IO1_Pos)
#define TSC_IOCCR_G5_IO1           TSC_IOCCR_G5_IO1_Msk
#define TSC_IOCCR_G5_IO2_Pos       (17U)
#define TSC_IOCCR_G5_IO2_Msk       (0x1UL << TSC_IOCCR_G5_IO2_Pos)
#define TSC_IOCCR_G5_IO2           TSC_IOCCR_G5_IO2_Msk
#define TSC_IOCCR_G5_IO3_Pos       (18U)
#define TSC_IOCCR_G5_IO3_Msk       (0x1UL << TSC_IOCCR_G5_IO3_Pos)
#define TSC_IOCCR_G5_IO3           TSC_IOCCR_G5_IO3_Msk
#define TSC_IOCCR_G5_IO4_Pos       (19U)
#define TSC_IOCCR_G5_IO4_Msk       (0x1UL << TSC_IOCCR_G5_IO4_Pos)
#define TSC_IOCCR_G5_IO4           TSC_IOCCR_G5_IO4_Msk
#define TSC_IOCCR_G6_IO1_Pos       (20U)
#define TSC_IOCCR_G6_IO1_Msk       (0x1UL << TSC_IOCCR_G6_IO1_Pos)
#define TSC_IOCCR_G6_IO1           TSC_IOCCR_G6_IO1_Msk
#define TSC_IOCCR_G6_IO2_Pos       (21U)
#define TSC_IOCCR_G6_IO2_Msk       (0x1UL << TSC_IOCCR_G6_IO2_Pos)
#define TSC_IOCCR_G6_IO2           TSC_IOCCR_G6_IO2_Msk
#define TSC_IOCCR_G6_IO3_Pos       (22U)
#define TSC_IOCCR_G6_IO3_Msk       (0x1UL << TSC_IOCCR_G6_IO3_Pos)
#define TSC_IOCCR_G6_IO3           TSC_IOCCR_G6_IO3_Msk
#define TSC_IOCCR_G6_IO4_Pos       (23U)
#define TSC_IOCCR_G6_IO4_Msk       (0x1UL << TSC_IOCCR_G6_IO4_Pos)
#define TSC_IOCCR_G6_IO4           TSC_IOCCR_G6_IO4_Msk
#define TSC_IOCCR_G7_IO1_Pos       (24U)
#define TSC_IOCCR_G7_IO1_Msk       (0x1UL << TSC_IOCCR_G7_IO1_Pos)
#define TSC_IOCCR_G7_IO1           TSC_IOCCR_G7_IO1_Msk
#define TSC_IOCCR_G7_IO2_Pos       (25U)
#define TSC_IOCCR_G7_IO2_Msk       (0x1UL << TSC_IOCCR_G7_IO2_Pos)
#define TSC_IOCCR_G7_IO2           TSC_IOCCR_G7_IO2_Msk
#define TSC_IOCCR_G7_IO3_Pos       (26U)
#define TSC_IOCCR_G7_IO3_Msk       (0x1UL << TSC_IOCCR_G7_IO3_Pos)
#define TSC_IOCCR_G7_IO3           TSC_IOCCR_G7_IO3_Msk
#define TSC_IOCCR_G7_IO4_Pos       (27U)
#define TSC_IOCCR_G7_IO4_Msk       (0x1UL << TSC_IOCCR_G7_IO4_Pos)
#define TSC_IOCCR_G7_IO4           TSC_IOCCR_G7_IO4_Msk
#define TSC_IOCCR_G8_IO1_Pos       (28U)
#define TSC_IOCCR_G8_IO1_Msk       (0x1UL << TSC_IOCCR_G8_IO1_Pos)
#define TSC_IOCCR_G8_IO1           TSC_IOCCR_G8_IO1_Msk
#define TSC_IOCCR_G8_IO2_Pos       (29U)
#define TSC_IOCCR_G8_IO2_Msk       (0x1UL << TSC_IOCCR_G8_IO2_Pos)
#define TSC_IOCCR_G8_IO2           TSC_IOCCR_G8_IO2_Msk
#define TSC_IOCCR_G8_IO3_Pos       (30U)
#define TSC_IOCCR_G8_IO3_Msk       (0x1UL << TSC_IOCCR_G8_IO3_Pos)
#define TSC_IOCCR_G8_IO3           TSC_IOCCR_G8_IO3_Msk
#define TSC_IOCCR_G8_IO4_Pos       (31U)
#define TSC_IOCCR_G8_IO4_Msk       (0x1UL << TSC_IOCCR_G8_IO4_Pos)
#define TSC_IOCCR_G8_IO4           TSC_IOCCR_G8_IO4_Msk

/* TSC_IOGCSR ----------------------------------------------------------- */
#define TSC_IOGCSR_G1E_Pos          (0U)
#define TSC_IOGCSR_G1E_Msk          (0x1UL << TSC_IOGCSR_G1E_Pos)
#define TSC_IOGCSR_G1E              TSC_IOGCSR_G1E_Msk
#define TSC_IOGCSR_G2E_Pos          (1U)
#define TSC_IOGCSR_G2E_Msk          (0x1UL << TSC_IOGCSR_G2E_Pos)
#define TSC_IOGCSR_G2E              TSC_IOGCSR_G2E_Msk
#define TSC_IOGCSR_G3E_Pos          (2U)
#define TSC_IOGCSR_G3E_Msk          (0x1UL << TSC_IOGCSR_G3E_Pos)
#define TSC_IOGCSR_G3E              TSC_IOGCSR_G3E_Msk
#define TSC_IOGCSR_G4E_Pos          (3U)
#define TSC_IOGCSR_G4E_Msk          (0x1UL << TSC_IOGCSR_G4E_Pos)
#define TSC_IOGCSR_G4E              TSC_IOGCSR_G4E_Msk
#define TSC_IOGCSR_G5E_Pos          (4U)
#define TSC_IOGCSR_G5E_Msk          (0x1UL << TSC_IOGCSR_G5E_Pos)
#define TSC_IOGCSR_G5E              TSC_IOGCSR_G5E_Msk
#define TSC_IOGCSR_G6E_Pos          (5U)
#define TSC_IOGCSR_G6E_Msk          (0x1UL << TSC_IOGCSR_G6E_Pos)
#define TSC_IOGCSR_G6E              TSC_IOGCSR_G6E_Msk
#define TSC_IOGCSR_G7E_Pos          (6U)
#define TSC_IOGCSR_G7E_Msk          (0x1UL << TSC_IOGCSR_G7E_Pos)
#define TSC_IOGCSR_G7E              TSC_IOGCSR_G7E_Msk
#define TSC_IOGCSR_G8E_Pos          (7U)
#define TSC_IOGCSR_G8E_Msk          (0x1UL << TSC_IOGCSR_G8E_Pos)
#define TSC_IOGCSR_G8E              TSC_IOGCSR_G8E_Msk
#define TSC_IOGCSR_G1S_Pos          (16U)
#define TSC_IOGCSR_G1S_Msk          (0x1UL << TSC_IOGCSR_G1S_Pos)
#define TSC_IOGCSR_G1S              TSC_IOGCSR_G1S_Msk
#define TSC_IOGCSR_G2S_Pos          (17U)
#define TSC_IOGCSR_G2S_Msk          (0x1UL << TSC_IOGCSR_G2S_Pos)
#define TSC_IOGCSR_G2S              TSC_IOGCSR_G2S_Msk
#define TSC_IOGCSR_G3S_Pos          (18U)
#define TSC_IOGCSR_G3S_Msk          (0x1UL << TSC_IOGCSR_G3S_Pos)
#define TSC_IOGCSR_G3S              TSC_IOGCSR_G3S_Msk
#define TSC_IOGCSR_G4S_Pos          (19U)
#define TSC_IOGCSR_G4S_Msk          (0x1UL << TSC_IOGCSR_G4S_Pos)
#define TSC_IOGCSR_G4S              TSC_IOGCSR_G4S_Msk
#define TSC_IOGCSR_G5S_Pos          (20U)
#define TSC_IOGCSR_G5S_Msk          (0x1UL << TSC_IOGCSR_G5S_Pos)
#define TSC_IOGCSR_G5S              TSC_IOGCSR_G5S_Msk
#define TSC_IOGCSR_G6S_Pos          (21U)
#define TSC_IOGCSR_G6S_Msk          (0x1UL << TSC_IOGCSR_G6S_Pos)
#define TSC_IOGCSR_G6S              TSC_IOGCSR_G6S_Msk
#define TSC_IOGCSR_G7S_Pos          (22U)
#define TSC_IOGCSR_G7S_Msk          (0x1UL << TSC_IOGCSR_G7S_Pos)
#define TSC_IOGCSR_G7S              TSC_IOGCSR_G7S_Msk
#define TSC_IOGCSR_G8S_Pos          (23U)
#define TSC_IOGCSR_G8S_Msk          (0x1UL << TSC_IOGCSR_G8S_Pos)
#define TSC_IOGCSR_G8S              TSC_IOGCSR_G8S_Msk

/* TSC_IOGXCR ----------------------------------------------------------- */
#define TSC_IOGXCR_CNT_Pos          (0U)
#define TSC_IOGXCR_CNT_Msk          (0x3FFFUL << TSC_IOGXCR_CNT_Pos)
#define TSC_IOGXCR_CNT              TSC_IOGXCR_CNT_Msk

#endif /* __STM32F0XX_TSC_BITS_H */
