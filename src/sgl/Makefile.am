AM_CFLAGS = \
	-I$(top_srcdir)/include/GL \
	-I$(top_srcdir)/src \
	-Wall -O2 -g
lib_LTLIBRARIES = libSGL.la
libSGL_la_LDFLAGS = \
		-lm \
		-version-info $(LIBSGL_CURRENT):$(LIBSGL_REVISION):$(LIBSGL_AGE)
libSGL_la_SOURCES = \
		config.h \
		gl.h \
		macros.h \
		sglapi.h \
		sglheader.h \
		types.h \
		color.c color.h \
		context.c context.h \
		depth.c depth.h \
		framebuffer.c framebuffer.h \
		geometry.c geometry.h \
		logging.c logging.h \
		matrix.c matrix.h \
		pipeline.c pipeline.h \
		polygon.c polygon.h \
		rasterize.c rasterize.h \
		renderbuffer.c renderbuffer.h \
		utils.c utils.h \
		viewport.c viewport.h \
		$(top_srcdir)/src/math/m_vector.c \
		$(top_srcdir)/src/math/m_vector.h \
		$(top_srcdir)/src/math/m_matrix.c \
		$(top_srcdir)/src/math/m_matrix.h
