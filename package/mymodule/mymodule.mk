MYMODULE_VERSION = 1.1
MYMODULE_SITE = $(call github,Orelgigi,buildroot-mymodule,v$(MYMODULE_VERSION))

$(eval $(kernel-module))
$(eval $(generic-package))
