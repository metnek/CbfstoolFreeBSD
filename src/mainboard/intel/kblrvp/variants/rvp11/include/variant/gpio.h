/*
 * This file is part of the coreboot project.
 *
 * Copyright (C) 2018 Intel Corporation.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
 * GNU General Public License for more details.
 */

#ifndef _GPIORVP11_H
#define _GPIORVP11_H

#include <soc/gpe.h>
#include <soc/gpio.h>

/* TCA6424A  I/O Expander */
#define IO_EXPANDER_BUS		4
#define IO_EXPANDER_0_ADDR	0x22
#define IO_EXPANDER_P0CONF	0x0C	/* Port 0 conf offset */
#define IO_EXPANDER_P0DOUT	0x04	/* Port 0 data offset */
#define IO_EXPANDER_P1CONF	0x0D
#define IO_EXPANDER_P1DOUT	0x05
#define IO_EXPANDER_P2CONF	0x0E
#define IO_EXPANDER_P2DOUT	0x06
#define IO_EXPANDER_1_ADDR	0x23

/* EC in RW */
#define GPIO_EC_IN_RW		GPP_C6
#define EC_SMI_GPI		GPP_I3

/* BIOS Flash Write Protect */
#define GPIO_PCH_WP		GPP_C23

/* Memory configuration board straps */
#define GPIO_MEM_CONFIG_0	GPP_C12
#define GPIO_MEM_CONFIG_1	GPP_C13
#define GPIO_MEM_CONFIG_2	GPP_C14
#define GPIO_MEM_CONFIG_3	GPP_C15

/* EC wake is LAN_WAKE# which is a special DeepSX wake pin */
#define GPE_EC_WAKE		GPE0_LAN_WAK

/* GPP_B16 is WLAN_WAKE. GPP_B group is routed to DW0 in the GPE0 block */
#define GPE_WLAN_WAKE		GPE0_DW0_16

/* Input device interrupt configuration */
#define TOUCHPAD_INT_L		GPP_B3_IRQ
#define TOUCHSCREEN_INT_L	GPP_E7_IRQ
#define MIC_INT_L		GPP_F10_IRQ

/* GPP_E16 is EC_SCI_L. GPP_E group is routed to DW2 in the GPE0 block */
#define EC_SCI_GPI		GPE0_DW2_16

#ifndef __ACPI__

/* Pad configuration in ramstage. */

static const struct pad_config gpio_table[] = {
/* EC_PCH_RCIN */	PAD_CFG_NF(GPP_A0, NONE, DEEP, NF1),
/* LPC_LAD_0 */		PAD_CFG_NF(GPP_A1, NONE, DEEP, NF1),
/* LPC_LAD_1 */		PAD_CFG_NF(GPP_A2, NONE, DEEP, NF1),
/* LPC_LAD_2 */		PAD_CFG_NF(GPP_A3, NONE, DEEP, NF1),
/* LPC_LAD_3 */		PAD_CFG_NF(GPP_A4, NONE, DEEP, NF1),
/* LPC_FRAME */		PAD_CFG_NF(GPP_A5, NONE, DEEP, NF1),
/* LPC_SERIRQ */	PAD_CFG_NF(GPP_A6, NONE, DEEP, NF1),
/* ESPI ALERT */	PAD_CFG_NF(GPP_A7, NONE, DEEP, NF2),
/* LPC_CLKRUN */	PAD_CFG_NF(GPP_A8, NONE, DEEP, NF1),
/* EC_LPC_CLK */	PAD_CFG_NF(GPP_A9, NONE, DEEP, NF1),
/* PCH_LPC_CLK */	PAD_CFG_NF(GPP_A10, NONE, DEEP, NF1),
/* EC_HID_INT */	PAD_CFG_GPI_APIC(GPP_A11, NONE, DEEP),
/* ISH_KB_PROX_INT */	PAD_CFG_GPI(GPP_A12, NONE, DEEP),
/* PCH_SUSPWRACB */	PAD_CFG_NF(GPP_A13, NONE, DEEP, NF1),
/* PM_SUS_STAT */	PAD_CFG_NF(GPP_A14, NONE, DEEP, NF1),
/* PCH_SUSACK */	PAD_CFG_NF(GPP_A15, NONE, DEEP, NF1),
/* SLP_S0ix_N */	PAD_CFG_GPO(GPP_A16, 1, DEEP),
/* M.2 WLAN PWR EN */	PAD_CFG_GPO(GPP_A17, 1, DEEP),
/* ACCEL INTERRUPT */	PAD_CFG_NF(GPP_A18, NONE, DEEP, NF1),
/* GPP_A19 */		PAD_CFG_NF(GPP_A19, NONE, DEEP, NF1),
/* GYRO_DRDY */		PAD_CFG_NF(GPP_A20, NONE, DEEP, NF1),
/* FLIP_ACCEL_INT */	PAD_CFG_NF(GPP_A21, NONE, DEEP, NF1),
/* GYRO_INT */		PAD_CFG_GPO(GPP_A22, 1, DEEP),
/* GPP_A23 */		PAD_CFG_GPI_APIC(GPP_A23, NONE, DEEP),

/* screen lock */	PAD_CFG_GPI(GPP_B0, NONE, DEEP),
/* Tch pnl pwren  */	PAD_CFG_GPO(GPP_B1, 1, DEEP),
/* HSJ_MIC_DET */
/* BT_RF_kill */	PAD_CFG_GPO(GPP_B3, 1, DEEP),
/* SNI_DRV_PCH */	PAD_CFG_NF(GPP_B4, NONE, DEEP, NF1),
/* M.2 BT UART wake */	PAD_CFG_GPI_APIC(GPP_B5, NONE, DEEP),
/* WIFI_CLK_REQ */
/* KEPLR_CLK_REQ */
/* SRCCLKREQ3# */	/* GPP_B8 */
/* SSD_CLK_REQ */
/* SRCCLKREQ5# */	/* GPP_B10 */
/* MPHY_EXT_PWR_GATE */	PAD_CFG_NF(GPP_B11, NONE, DEEP, NF1),
/* PM_SLP_S0 */		PAD_CFG_NF(GPP_B12, NONE, DEEP, NF1),
/* PCH_PLT_RST */	PAD_CFG_NF(GPP_B13, NONE, DEEP, NF1),
/* GPP_B_14_SPKR */	PAD_CFG_GPI_ACPI_SMI(GPP_B14, NONE, DEEP, YES),
/* GSPI0_CS# */		/* GPP_B15 */
/* WLAN_PCIE_WAKE */	PAD_CFG_GPI_ACPI_SCI(GPP_B16, NONE, DEEP, YES),
/* SSD_PCIE_WAKE */	PAD_CFG_GPO(GPP_B17, 1, DEEP),
/* GSPI0_MOSI */	PAD_CFG_GPO(GPP_B18, 1, DEEP),
/* CCODEC_SPI_CS */	PAD_CFG_NF(GPP_B19, NONE, DEEP, NF1),
/* CODEC_SPI_CLK */	PAD_CFG_NF(GPP_B20, NONE, DEEP, NF1),
/* CODEC_SPI_MISO */	PAD_CFG_NF(GPP_B21, NONE, DEEP, NF1),
/* CODEC_SPI_MOSI */	PAD_CFG_NF(GPP_B22, NONE, DEEP, NF1),
/* SM1ALERT# */		PAD_CFG_GPO(GPP_B23, 1, DEEP),

/* SMB_CLK */		PAD_CFG_NF(GPP_C0, NONE, DEEP, NF1),
/* SMB_DATA */		PAD_CFG_NF(GPP_C1, NONE, DEEP, NF1),
/* SMBALERT# */		PAD_CFG_GPI(GPP_C2, NONE, DEEP),
/* M2_WWAN_PWREN */	PAD_CFG_NF(GPP_C3, NONE, DEEP, NF1),
/* SML0DATA */		PAD_CFG_NF(GPP_C4, NONE, DEEP, NF1),
/* SML0ALERT# */	PAD_CFG_GPI(GPP_C5, NONE, DEEP),
/* EC_IN_RW */		PAD_CFG_NF(GPP_C6, NONE, DEEP, NF1),
/* USB_CTL */		PAD_CFG_NF(GPP_C7, NONE, DEEP, NF1),
/* UART0_RXD */		PAD_CFG_NF(GPP_C8, NONE, DEEP, NF1),
/* UART0_TXD */		PAD_CFG_NF(GPP_C9, NONE, DEEP, NF1),
/* NFC_RST* */		PAD_CFG_NF(GPP_C10, NONE, DEEP, NF1),
/* EN_PP3300_KEPLER */	PAD_CFG_NF(GPP_C11, NONE, DEEP, NF1),
/* PCH_MEM_CFG0 */	PAD_CFG_NF(GPP_C12, NONE, DEEP, NF1),
/* PCH_MEM_CFG1 */	PAD_CFG_NF(GPP_C13, NONE, DEEP, NF1),
/* PCH_MEM_CFG2 */	PAD_CFG_NF(GPP_C14, NONE, DEEP, NF1),
/* PCH_MEM_CFG3 */	PAD_CFG_NF(GPP_C15, NONE, DEEP, NF1),
/* I2C0_SDA */		PAD_CFG_NF(GPP_C16, NONE, DEEP, NF1),
/* I2C0_SCL */		PAD_CFG_NF(GPP_C17, NONE, DEEP, NF1),
/* I2C1_SDA */		PAD_CFG_NF(GPP_C18, NONE, DEEP, NF1),
/* I2C1_SCL */		PAD_CFG_NF(GPP_C19, NONE, DEEP, NF1),
/* GD_UART2_RXD */	PAD_CFG_NF(GPP_C20, NONE, DEEP, NF1),
/* GD_UART2_TXD */	PAD_CFG_NF(GPP_C21, NONE, DEEP, NF1),
/* TCH_PNL_PWREN */	PAD_CFG_NF(GPP_C22, NONE, DEEP, NF1),
/* SPI_WP_STATUS */	PAD_CFG_NF(GPP_C23, NONE, DEEP, NF1),

/* ITCH_SPI_CS */	PAD_CFG_NF(GPP_D0, NONE, DEEP, NF1),
/* ITCH_SPI_CLK */	PAD_CFG_NF(GPP_D1, NONE, DEEP, NF1),
/* ITCH_SPI_MISO_1 */	PAD_CFG_NF(GPP_D2, NONE, DEEP, NF1),
/* ITCH_SPI_MISO_0 */	PAD_CFG_NF(GPP_D3, NONE, DEEP, NF1),
/* CAM_FLASH_STROBE */	PAD_CFG_NF(GPP_D4, NONE, DEEP, NF1),
/* EN_PP3300_DX_EMMC */	PAD_CFG_NF(GPP_D5, NONE, DEEP, NF1),
/* EN_PP1800_DX_EMMC */	PAD_CFG_NF(GPP_D6, NONE, DEEP, NF1),
/* SH_I2C1_SDA */	PAD_CFG_NF(GPP_D7, NONE, DEEP, NF1),
/* SH_I2C1_SCL */	PAD_CFG_NF(GPP_D8, NONE, DEEP, NF1),
/* TBD */
/* USB_A0_ILIM_SEL */	PAD_CFG_GPO(GPP_D10, 1, DEEP),
/* USB_A1_ILIM_SEL */
/* EN_PP3300_DX_CAM */
/* EN_PP1800_DX_AUDIO */PAD_CFG_NF(GPP_D13, NONE, DEEP, NF1),
/* ISH_UART0_TXD */	PAD_CFG_NF(GPP_D14, NONE, DEEP, NF1),
/* ISH_UART0_RTS */	PAD_CFG_NF(GPP_D15, NONE, DEEP, NF1),
/* ISH_UART0_CTS */	PAD_CFG_NF(GPP_D16, NONE, DEEP, NF1),
/* DMIC_CLK_1 */	PAD_CFG_NF(GPP_D17, NONE, DEEP, NF1),
/* DMIC_DATA_1 */	PAD_CFG_NF(GPP_D18, NONE, DEEP, NF1),
/* DMIC_CLK_0 */	PAD_CFG_NF(GPP_D19, NONE, DEEP, NF1),
/* DMIC_DATA_0 */	PAD_CFG_NF(GPP_D20, NONE, DEEP, NF1),
/* ITCH_SPI_D2 */	PAD_CFG_NF(GPP_D21, NONE, DEEP, NF1),
/* ITCH_SPI_D3 */	PAD_CFG_NF(GPP_D22, NONE, DEEP, NF1),
/* I2S_MCLK */		PAD_CFG_NF(GPP_D23, NONE, DEEP, NF1),

/* SPI_TPM_IRQ */	PAD_CFG_NF(GPP_E0, NONE, DEEP, NF1),
/* SATAXPCIE1 */	PAD_CFG_NF(GPP_E1, NONE, DEEP, NF3),
/* SSD_PEDET */		PAD_CFG_NF(GPP_E2, NONE, DEEP, NF3),
/* CPU_GP0 */		PAD_CFG_NF(GPP_E3, NONE, DEEP, NF1),
/* SSD_SATA_DEVSLP */	PAD_CFG_NF(GPP_E4, NONE, DEEP, NF1),
/* SATA_DEVSLP1 */	/* GPP_E5 */
/* SATA_DEVSLP2 */	PAD_CFG_NF(GPP_E6, NONE, DEEP, NF3),
/* TCH_PNL_INTR* */
/* SATALED# */		PAD_CFG_NF(GPP_E8, NONE, DEEP, NF1),
/* USB2_OC_0 */		PAD_CFG_NF(GPP_E9, NONE, DEEP, NF1),
/* USB2_OC_1 */		PAD_CFG_NF(GPP_E10, NONE, DEEP, NF1),
/* USB2_OC_2 */		PAD_CFG_NF(GPP_E11, NONE, DEEP, NF1),
/* USB2_OC_3 */		PAD_CFG_NF(GPP_E12, NONE, DEEP, NF1),
/* I2S2_SCLK */		PAD_CFG_NF(GPP_F0, NONE, DEEP, NF1),
/* I2S2_SFRM */		PAD_CFG_NF(GPP_F1, NONE, DEEP, NF1),
/* I2S2_TXD */		PAD_CFG_GPO(GPP_F2, 0, DEEP),
/* I2S2_RXD */		PAD_CFG_GPO(GPP_F3, 1, DEEP),
/* I2C2_SDA */		PAD_CFG_GPO(GPP_F4, 0, DEEP),
/* I2C2_SCL */		PAD_CFG_GPI_APIC(GPP_F5, NONE, DEEP),
/* I2C3_SDA */		PAD_CFG_GPO(GPP_F6, 0, DEEP),
/* I2C3_SCL */		PAD_CFG_GPO(GPP_F7, 0, DEEP),
/* I2C4_SDA */		PAD_CFG_GPI(GPP_F8, NONE, DEEP),
/* I2C4_SDA */		PAD_CFG_GPI_APIC(GPP_F9, NONE, DEEP),
/* AUDIO_IRQ */		PAD_CFG_GPI(GPP_F10, NONE, DEEP),
/* I2C5_SCL */		PAD_CFG_GPI(GPP_F11, NONE, DEEP),
/* EMMC_CMD */		PAD_CFG_GPI_ACPI_SCI(GPP_F12, NONE, DEEP, YES),
/* EMMC_DATA0 */	PAD_CFG_GPI(GPP_F13, NONE, DEEP),
/* EMMC_DATA1 */	PAD_CFG_GPI(GPP_F14, NONE, DEEP),
/* EMMC_DATA2 */	PAD_CFG_NF(GPP_F15, NONE, DEEP, NF1),
/* EMMC_DATA3 */	PAD_CFG_NF(GPP_F16, NONE, DEEP, NF1),
/* EMMC_DATA4 */	PAD_CFG_GPO(GPP_F17, 1, DEEP),
/* EMMC_DATA5 */	PAD_CFG_GPO(GPP_F18, 1, DEEP),
/* EMMC_DATA6 */	PAD_CFG_NF(GPP_F19, NONE, DEEP, NF1),
/* EMMC_DATA7 */	PAD_CFG_NF(GPP_F20, NONE, DEEP, NF1),
/* EMMC_RCLK */		PAD_CFG_NF(GPP_F21, NONE, DEEP, NF1),
/* EMMC_CLK */		PAD_CFG_GPO(GPP_F22, 1, DEEP),
/* GPP_F23 */

/* SD_CMD */		PAD_CFG_GPI_APIC(GPP_G0, 20K_PD, DEEP),
/* SD_DATA0 */		PAD_CFG_GPO(GPP_G1, 1, DEEP),
/* SD_DATA1 */		PAD_CFG_NF(GPP_G2, NONE, DEEP, NF1),
/* SD_DATA2 */		PAD_CFG_GPI_ACPI_SCI(GPP_G3, NONE, DEEP, YES),
/* SD_DATA3 */		PAD_CFG_GPO(GPP_G4, 0, DEEP),
/* SD_CD# */		PAD_CFG_GPO(GPP_G5, 0, DEEP),
/* SD_CLK */		PAD_CFG_GPO(GPP_G6, 1, DEEP),
/* SD_WP */		PAD_CFG_GPI_APIC(GPP_G7, NONE, DEEP),
/* TBD */		PAD_CFG_GPO(GPP_G8, 1, DEEP),
/* TBD */		PAD_CFG_GPO(GPP_G9, 1, DEEP),
/* TBD */		PAD_CFG_GPO(GPP_G10, 0, DEEP),
/* TBD */		PAD_CFG_GPO(GPP_G11, 1, DEEP),
/* TBD */		PAD_CFG_GPI_ACPI_SCI(GPP_G12, 20K_PD, DEEP, YES),
/* TBD */		PAD_CFG_GPO(GPP_G13, 1, DEEP),
/* TBD */
/* TBD */		PAD_CFG_GPO(GPP_G15, 1, DEEP),
/* TBD */		PAD_CFG_GPO(GPP_G16, 0, DEEP),
/* TBD */		PAD_CFG_GPO(GPP_G17, 1, DEEP),
/* TBD */		PAD_CFG_GPI_ACPI_SCI(GPP_G18, NONE, DEEP, YES),
/* TBD */
/* TBD */		PAD_CFG_GPO(GPP_G20, 1, DEEP),
/* TBD */		PAD_CFG_GPI_APIC(GPP_G21, 20K_PD, DEEP),
/* TBD */		PAD_CFG_GPO(GPP_G22, 1, DEEP),
/* TBD */		PAD_CFG_GPO(GPP_G23, 1, DEEP),

/* SD_CMD */		PAD_CFG_NF(GPP_H0, NONE, DEEP, NF1),
/* SD_DATA0 */
/* SD_DATA1 */		PAD_CFG_NF(GPP_H2, NONE, DEEP, NF1),
/* SD_DATA2 */
/* SD_DATA3 */		PAD_CFG_GPO(GPP_H4, 0, DEEP),
/* SD_CD# */		PAD_CFG_NF(GPP_H5, NONE, DEEP, NF1),
/* SD_CLK */		PAD_CFG_GPO(GPP_H6, 1, DEEP),
/* SD_WP */		PAD_CFG_GPO(GPP_H7, 1, DEEP),
/* TBD */		PAD_CFG_GPO(GPP_H8, 1, DEEP),
/* TBD */		PAD_CFG_GPO(GPP_H9, 1, DEEP),
/* TBD */		PAD_CFG_GPO(GPP_H10, 1, DEEP),
/* TBD */		PAD_CFG_GPO(GPP_H11, 1, DEEP),
/* TBD */
/* TBD */		PAD_CFG_GPI(GPP_H13, NONE, DEEP),
/* TBD */		PAD_CFG_GPI(GPP_H14, NONE, DEEP),
/* TBD */		PAD_CFG_GPI(GPP_H15, NONE, DEEP),
/* TBD */		PAD_CFG_GPO(GPP_H16, 1, DEEP),
/* TBD */		PAD_CFG_GPO(GPP_H17, 1, DEEP),
/* TBD */		PAD_CFG_GPO(GPP_H18, 1, DEEP),
/* TBD */		PAD_CFG_NF(GPP_H19, NONE, DEEP, NF1),
/* TBD */		PAD_CFG_NF(GPP_H20, NONE, DEEP, NF1),
/* TBD */		PAD_CFG_NF(GPP_H21, NONE, DEEP, NF1),
/* TBD */		PAD_CFG_NF(GPP_H22, NONE, DEEP, NF1),
/* TBD */		PAD_CFG_GPO(GPP_H23, 0, DEEP),

/* DDSP_HPD_0 */        PAD_CFG_NF(GPP_I0, NONE, DEEP, NF1),
/* DDSP_HPD_1 */        PAD_CFG_NF(GPP_I1, NONE, DEEP, NF1),
/* DDSP_HPD_2 */        PAD_CFG_NF(GPP_I2, NONE, DEEP, NF1),
/* DDSP_HPD_3 */        PAD_CFG_GPI_ACPI_SMI(GPP_I3, NONE, DEEP, YES),
/* SD_CMD */		PAD_CFG_NF(GPP_I4, NONE, DEEP, NF1),
/* SD_CMD */		PAD_CFG_NF(GPP_I5, NONE, DEEP, NF1),
/* SD_CMD */		PAD_CFG_NF(GPP_I6, NONE, DEEP, NF1),
/* SD_CMD */		PAD_CFG_NF(GPP_I7, NONE, DEEP, NF1),
/* SD_CMD */		PAD_CFG_NF(GPP_I8, NONE, DEEP, NF1),
/* SD_CMD */		PAD_CFG_NF(GPP_I9, NONE, DEEP, NF1),
/* SD_CMD */		PAD_CFG_NF(GPP_I10, NONE, DEEP, NF1),

/* PCH_BATLOW */	PAD_CFG_NF(GPD0, NONE, DEEP, NF1),
/* EC_PCH_ACPRESENT */	PAD_CFG_NF(GPD1, NONE, DEEP, NF1),
/* EC_PCH_WAKE */	PAD_CFG_NF(GPD2, NONE, DEEP, NF1),
/* EC_PCH_PWRBTN */	PAD_CFG_NF(GPD3, NONE, DEEP, NF1),
/* PM_SLP_S3# */	PAD_CFG_NF(GPD4, NONE, DEEP, NF1),
/* PM_SLP_S4# */	PAD_CFG_NF(GPD5, NONE, DEEP, NF1),
/* PM_SLP_SA# */	PAD_CFG_NF(GPD6, NONE, DEEP, NF1),
			/* GPD7 */
/* PM_SUSCLK */		PAD_CFG_NF(GPD8, NONE, DEEP, NF1),
/* PCH_SLP_WLAN# */	PAD_CFG_NF(GPD9, NONE, DEEP, NF1),
/* PM_SLP_S5# */	PAD_CFG_NF(GPD10, NONE, DEEP, NF1),
/* LANPHYC */		PAD_CFG_NF(GPD11, NONE, DEEP, NF1),
};

/* Early pad configuration in romstage. */
static const struct pad_config early_gpio_table[] = {
/* UART0_RXD */		PAD_CFG_NF(GPP_C8, NONE, DEEP, NF1),
/* UART0_TXD */		PAD_CFG_NF(GPP_C9, NONE, DEEP, NF1),
};

#endif
#endif
