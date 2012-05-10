package x10firm;

import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;

import polyglot.frontend.Goal;
import polyglot.frontend.Job;
import polyglot.frontend.SourceGoal_c;

/** Dumps a job/goal hierarchy as graph in vcg format. */
public final class GoalGraphDumper {
	private final Map<Goal, String> goalNames = new HashMap<Goal, String>();
	private final Map<Job, String> jobNames = new HashMap<Job, String>();
	private final PrintWriter writer;
	private int nextNr;

	private void dumpLabel(final Goal goal) {
		if (goal instanceof SourceGoal_c) {
			final SourceGoal_c source = (SourceGoal_c) goal;
			writer.print(source.name() + "(" + source.state() + ")");
		} else {
			writer.print(goal.toString());
		}
	}

	private GoalGraphDumper(final PrintWriter writer) {
		this.writer = writer;
	}

	private String dumpJob(final Job job) {
		final String existingName = jobNames.get(job);
		if (existingName != null)
			return existingName;

		final String name = "j" + (nextNr++);
		jobNames.put(job, name);
		writer.printf("node: { title: \"%s\" label:\"%s\" color:100 }\n", name, job);
		return name;
	}

	private String dumpGoal(final Goal goal) {
		final String existingName = goalNames.get(goal);
		if (existingName != null)
			return existingName;

		final String name = "n" + (nextNr++);
		goalNames.put(goal, name);
		writer.printf("node: { title: \"%s\" label:\"", name);
		dumpLabel(goal);
		writer.print("\"}\n");

		if (goal instanceof SourceGoal_c) {
			final SourceGoal_c source = (SourceGoal_c) goal;
			final String job = dumpJob(source.job());
			writer.printf("edge: { sourcename: \"%s\" targetname: \"%s\" class:2 color:100 }\n", name, job);
		}

		/* dump edges */
		for (final Goal prereq : goal.prereqs()) {
			final String prereqName = dumpGoal(prereq);
			writer.printf("edge: { sourcename: \"%s\" targetname: \"%s\" class:1 }\n", name, prereqName);
		}

		return name;
	}

	private void dumpGoalGraph(final Goal root) {
		writer.print("graph: {\n"
				+ "title: \"goal graph\"\n"
				+ "layoutalgorithm: mindepth //$ \"hierarchic\"\n"
				+ "manhattan_edges: yes\n"
				+ "orientation: bottom_to_top\n"
				+ "classname 1: \"Goals\"\n"
				+ "classname 2: \"JobLinks\"\n"
				+ "colorentry 100: 153 153 255");
		dumpGoal(root);
		writer.print("}\n");
	}

	/** Dumps a goal graph in vcg format. */
	public static void dumpGoalGraph(final PrintWriter writer, final Goal root) {
		final GoalGraphDumper dumper = new GoalGraphDumper(writer);
		dumper.dumpGoalGraph(root);
	}
}
