# Jmdb - A J2ME debugger with Emacs interface
# Copyright (C) <2007>  Wei Hu <wei.hu.tw@gmail.com>
# 
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

include $(BUILD_MAK_DIR)/config.mak

BUILD_I18N_SUB_DIR = zh_TW.Big5

all:
	@for i in $(BUILD_I18N_SUB_DIR); do \
		cd $$i; \
		$(MAKE) || exit 1; \
		cd $(BUILD_I18N_DIR); \
	done

install:
	@for i in $(BUILD_I18N_SUB_DIR); do\
		cd $$i; \
		$(MAKE) install || exit 1; \
		cd $(BUILD_I18N_DIR); \
	done

clean:
	@for i in $(BUILD_I18N_SUB_DIR); do \
		cd $$i; \
		$(MAKE) clean || exit 1; \
		cd $(I18N_DIR); \
	done
